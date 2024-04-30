/*************************************************** 
  This is an example sketch for our optical Fingerprint sensor

  Designed specifically to work with the Adafruit BMP085 Breakout 
  ----> http://www.adafruit.com/products/751

  These displays use TTL Serial to communicate, 2 pins are required to 
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
  MODIFIED BY AATIK'S LAB 
 ****************************************************/
//modified by DPV technology for testing//

//Fingerprint
#include <Adafruit_Fingerprint.h>
#include <Servo.h>

#include <LiquidCrystal_I2C.h>

//Radio
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


#include <Keypad.h>
RF24 radio(11, 10); // CE, CSN

const byte slaveAddress[5] = {'R','x','A','A','A'};

char dataToSend[10] = "Message 0";
char txNum = '0';


unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 1000; // send once per second

Servo myservo0;

constexpr uint8_t servoPin = 11;
int pot0 = A0;
int val0;
char password[4];   // Variable to store users password
bool FingerprintMode = true; // boolean to change modes
//char key_pressed = 0; // Variable to store incoming keys
uint8_t i = 0;  // Variable used for counter
int in1= 8;
int in2= 9;
// Create instances
LiquidCrystal_I2C lcd(0x27, 16, 2);
//Initializing password
char initial_password[4]={'1','2','3','4'};
// defining how many rows and columns our keypad have
const byte rows = 4;
const byte columns = 3;
// Keypad pin map
char hexaKeys[rows][columns] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
// Initializing pins for keypad
byte row_pins[rows] = {A0, A1, A2, A3};
byte column_pins[columns] = {2, 5, 6};
// Create instance for keypad
Keypad keypad_key = Keypad( makeKeymap(hexaKeys), row_pins, column_pins, rows, columns);
// On Leonardo/Micro or others with hardware serial, use those! #0 is green wire, #1 is white
// uncomment this line:
//#define mySerial Serial

// For UNO and others without hardware serial, we must use software serial...
// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// comment these two lines if using hardware serial
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
void setup()  
{

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  //Radio
  Serial.begin(9600);
  radio.begin();
  radio.setDataRate( RF24_250KBPS );
  radio.setRetries(2,5);
  radio.setAutoAck(true);
  if(!radio.begin()){
    Serial.print("Failed to begin");
  }
  radio.stopListening();
  radio.openWritingPipe(slaveAddress);

  
  //LCD
  lcd.begin();//LCD Screen
  //lcd.backlight();
  SPI.begin();
  lcd.clear();
  lcd.display();
  //Fingerprint

  //while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  //Serial.println("\n\nAdafruit finger detect test");

  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
  

  
}

void loop()                     // run over and over again
{
  
  if (FingerprintMode==true){
    lcd.setCursor(3,0);
    lcd.print("Waiting for ");
    lcd.setCursor(2,1);
    lcd.print("valid finger...");
    if (getFingerprintIDez()!=-1){
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Fingerprint");
      lcd.setCursor(4,1);
      lcd.print("Matched");
      Serial.print("Fingerprint Matched ");
      
      delay(3000);
      lcd.clear();
      Serial.print("Enter password");
      lcd.print("Enter Password");
      FingerprintMode=false;
    }else{
      //Serial.print("Fingerprint Not Matched ");
    }
  }
  if (FingerprintMode==false){
    
    char key_pressed = keypad_key.getKey(); // Storing keys
    if (key_pressed)
    {
      
      password[i++] = key_pressed; // Storing in password variable
      Serial.print("*");
      lcd.setCursor(i+3,1);
      lcd.print("*");
    }
    if (i == 4) // If 4 keys are completed
    {
      delay(200);
      if (!(strncmp(password, initial_password, 4))) // If password is matched
      {
        lcd.clear();
        lcd.print("Accepted");
        lcd.setCursor(0,1);
        lcd.print("Door Unlocking...");
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        delay(25000);
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        delay(4000);
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        delay(2500);
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        //currentMillis = millis();
        //if (currentMillis - prevMillis >= txIntervalMillis) {
        //send();
        //prevMillis = millis();
        //}
        /*const char text[] = "true";
        if(radio.write(&text, sizeof(text))){
          Serial.print("yay");
        }else{
          Serial.print("nooo");
        }
        Serial.print(text);
        delay(5000);*/
        lcd.clear();
        i=0;
        FingerprintMode=true;
      
      }else{
        Serial.print("password not Matched");

        lcd.clear();
        lcd.print("Wrong Password");
        delay(3000);
        lcd.clear();
        i=0;
        FingerprintMode=true;
      }

    }
  }
  delay(50);            //don't ned to run this at full speed.

}


 void send() {

    bool rslt;
    rslt = radio.write( &dataToSend, sizeof(dataToSend) );
        // Always use sizeof() as it gives the size as the number of bytes.
        // For example if dataToSend was an int sizeof() would correctly return 2

    Serial.print("Data Sent ");
    Serial.print(dataToSend);
    if (rslt) {
        Serial.println("  Acknowledge received");
    }
    else {
        Serial.println("  Tx failed");
    }
}


uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!




 val0= analogRead(pot0);
 val0= map(val0,0,1024,0,180);
myservo0.write(val0);

  
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
}
