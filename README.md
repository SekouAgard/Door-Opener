# Door-Opener
When trying to re-create this project you first want to order the items listed below. You will also need to buy wires. While they are arriving go ahead and 3D print the files in the 
DoorOpener.f3d v8.stl. Once the materials have arrived and the parts have been printed your going to attach the gear onto the dc motor and insert the gear rack into the base. Next add put the part that 
pushes the door handle in between the two small holes and push the small rode into them. In terms of how to get the motor to stay on the base you can either use duck tape, glue, or find a way to screw it
down.

Next you want to attach the battery pack and L298N Motor Driver to the base. You are going to connect the two wires of the motor to OUT1 and OUT2 then screw them in tight so they dont move. You then 
are going to cut DC barrel jack off the battery pack and attach to wires, red and black, to the positive and negative wires of the battery pack respectively. Next you will attach the positive wire to the 12V
input and the black wire to the ground input. You can also use the same ways you did to hold down the L298N motor drive and battery pack as you did with the motor. The door opener attachment is now 
completed. 

Now to put together the two factor authentication. When connecting the wires sauder them on to the first three holes and the last four. In whic you are skipping the fourth hole. You will take the arduino uno and attach the keypad the first three wires from left to right to the 2,5 and 6 inputs respectively. You will then attach the last four wires to A0, A1, A2, and A3 respectively. Once completed you will take the LCD IC and attach the GND to the arduino GND, the VCC to the arduino 5V, the SDA to the ardunio SDA and the SCL to the arduino SCL. For the fingerprint sensor you will attach the black wire to ground, the red wire to Vin, the green wire to input 3 and the white wire to input 4.

Now time to connect the arduino uno to the L298N motor driver. You will attach a wire from ground on the arduino to the ground on the motor driver first. Then input 9 will be IN2 while input 8 will be IN1. Run these wires to the corresponding IN1 and IN2 on the motor driver. You will then also have another battery pack to power the arduino. With that everything should be connected and all thats left is to upload the code.

You will want to download the arduino IDE and open the FINGERPRINT_WITH_SERVO code. Next download the necessary libraries such as adafruit fingerprint sensor, adafruit liquid crystal I2C and Keypad. You will then upload that code to the arduino and your door opener should be ready to go. Check to make sure all wires are connected, not broken, motor is stuck in place and that everything is operating corrrectly.


Materials
Arduino Uno: https://www.amazon.com/ELEGOO-Board-ATmega328P-ATMEGA16U2-Compliant/dp/B01EWOE0UU?pd_rd_w=uHBCD&content-id=amzn1.sym.d3245d74-f79b-49f3-b99c-1e231bb8ca7c&pf_rd_p=d3245d74-f79b-49f3-b99c-1e231bb8ca7c&pf_rd_r=EQQZ30FES1N7RXBWGESE&pd_rd_wg=6mjU1&pd_rd_r=abb9955b-90aa-4816-838a-028d2ca6d37b&pd_rd_i=B01EWOE0UU&psc=1&ref_=pd_bap_m_grid_dv_rp_0_2_t

DC Gear Motor: https://www.amazon.com/BRINGSMART-70kg-cm-Self-locking-Reversed-Rotating/dp/B07F8Y36PD?pd_rd_w=uHBCD&content-id=amzn1.sym.d3245d74-f79b-49f3-b99c-1e231bb8ca7c&pf_rd_p=d3245d74-f79b-49f3-b99c-1e231bb8ca7c&pf_rd_r=EQQZ30FES1N7RXBWGESE&pd_rd_wg=6mjU1&pd_rd_r=abb9955b-90aa-4816-838a-028d2ca6d37b&pd_rd_i=B07F8Y36PD&psc=1&ref_=pd_bap_m_grid_dv_rp_0_3_i

Fingerprint Sensor: https://www.amazon.com/Optical-Fingerprint-Control-Mega2560-Geekstory/dp/B07BQ9VNWR?pd_rd_w=uHBCD&content-id=amzn1.sym.d3245d74-f79b-49f3-b99c-1e231bb8ca7c&pf_rd_p=d3245d74-f79b-49f3-b99c-1e231bb8ca7c&pf_rd_r=EQQZ30FES1N7RXBWGESE&pd_rd_wg=6mjU1&pd_rd_r=abb9955b-90aa-4816-838a-028d2ca6d37b&pd_rd_i=B07BQ9VNWR&psc=1&ref_=pd_bap_m_grid_dv_rp_0_20_i

L298N Motor Driver: https://www.amazon.com/DIYables-Driver-Arduino-ESP8266-Raspberry/dp/B0C7B6S4L9?pd_rd_w=uHBCD&content-id=amzn1.sym.d3245d74-f79b-49f3-b99c-1e231bb8ca7c&pf_rd_p=d3245d74-f79b-49f3-b99c-1e231bb8ca7c&pf_rd_r=EQQZ30FES1N7RXBWGESE&pd_rd_wg=6mjU1&pd_rd_r=abb9955b-90aa-4816-838a-028d2ca6d37b&pd_rd_i=B0C7B6S4L9&psc=1&ref_=pd_bap_m_grid_dv_rp_0_22_i

4x4 Matrix Keypad: https://www.amazon.com/DIYmalls-Keypad-Membrane-Keyboard-Arduino/dp/B086ZGKDK9?pd_rd_w=3Ei9o&content-id=amzn1.sym.b854a5c2-4475-41f8-a6d4-df92b2868104&pf_rd_p=b854a5c2-4475-41f8-a6d4-df92b2868104&pf_rd_r=XRTHQV2EF22XRZDCP2AP&pd_rd_wg=5HyAd&pd_rd_r=88f942f3-0775-4240-b3f4-93e0b6070cf0&pd_rd_i=B086ZGKDK9&psc=1&ref_=pd_basp_m_rpt_ba_s_2_sc

LCD Display: https://www.amazon.com/SunFounder-Serial-Module-Display-Arduino/dp/B019K5X53O?pd_rd_w=xq3j8&content-id=amzn1.sym.b854a5c2-4475-41f8-a6d4-df92b2868104&pf_rd_p=b854a5c2-4475-41f8-a6d4-df92b2868104&pf_rd_r=19H3RT85PSRSSJPSX12Y&pd_rd_wg=8pps8&pd_rd_r=10bbd005-7684-4229-8d3e-5b0e4684d549&pd_rd_i=B019K5X53O&psc=1&ref_=pd_basp_m_rpt_ba_s_1_sc

Battery Pack: https://www.amazon.com/Battery-Holder-Barrel-Connector-Arduino/dp/B07T65WWCR?pd_rd_w=c944c&content-id=amzn1.sym.b854a5c2-4475-41f8-a6d4-df92b2868104&pf_rd_p=b854a5c2-4475-41f8-a6d4-df92b2868104&pf_rd_r=RZ3ECVJ4CPRFG3CZG5TM&pd_rd_wg=WNnfT&pd_rd_r=a3906e23-a5ca-4591-a204-aae7dd65954c&pd_rd_i=B07T65WWCR&psc=1&ref_=pd_basp_m_rpt_ba_s_1_sc
