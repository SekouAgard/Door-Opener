# Door-Opener
https://github.com/nRF24/RF24.git
When trying to re-create this project you first want to order the items listed in the materials folder. You will also need to buy wires. While they are arriving go ahead and 3D print the files in the 
DoorOpener.f3d v8.stl. Once the materials have arrived and the parts have been printed your going to attach the gear onto the dc motor and insert the gear rack into the base. Next add put the part that 
pushes the door handle in between the two small holes and push the small rode into them. In terms of how to get the motor to stay on the base you can either use duck tape, glue, or find a way to screw it
down.

Next you want to attach the battery pack and L298N Motor Driver to the base. You are going to connect the two wires of the motor to OUT1 and OUT2 then screw them in tight so they dont move. You then 
are going to cut DC barrel jack off the battery pack and attach to wires, red and black, to the positive and negative wires of the battery pack respectively. Next you will attach the positive wire to the 12V
input and the black wire to the ground input. You can also use the same ways you did to hold down the L298N motor drive and battery pack as you did with the motor. The door opener attachment is now 
completed. 

Now to put together the two factor authentication. When connecting the wires sauder them on to the first three holes and the last four. In whic you are skipping the fourth hole. You will take the arduino uno and attach the keypad the first three wires from left to right to the 2,5 and 6 inputs respectively. You will then attach the last four wires to A0, A1, A2, and A3 respectively. Once completed you will take the LCD IC and attach the GND to the arduino GND, the VCC to the arduino 5V, the SDA to the ardunio SDA and the SCL to the arduino SCL. For the fingerprint sensor you will attach the black wire to ground, the red wire to Vin, the green wire to input 3 and the white wire to input 4.

Now time to connect the arduino uno to the L298N motor driver. You will attach a wire from ground on the arduino to the ground on the motor driver first. Then input 9 will be IN2 while input 8 will be IN1. Run these wires to the corresponding IN1 and IN2 on the motor driver. With that everything should be connected and all thats left is to upload the code.

You will want to download the arduino IDE and open the FINGERPRINT_WITH_SERVO code and compile to to make sure it works. You will then upload that code to the arduino and your door opener should be ready to go. Check to make sure all wires are connected, not broken, motor is stuck in place and that everything is operating corrrectly.
