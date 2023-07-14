# Autonomous-car
This project aims to implement a self-driving Car that can avoid the  obstacles with very fast response:
# System Discripation
• It is a vehicle that have ability of sensing its environment and operating 
without human involvement.  
• It senses using ultrasonics sensor rotating with servo motor in 180 degree
range.   
• When the sensor send signal to the ATMega 32 chip which says that there 
is an obstacle. The car stops and ultrasonic start scanning right and left to 
see where is the more free place to move in it. if the left and right distance 
is 40 cm or less it moves backward, and check left and right again.  
• All this code of scanning is written in the while (1).     
# Specifications –ultrasonic Sensor, L293D, LCD, Servo

1. Ultrasonic is used to detect any obstacles towards to the car, and 
the car must fast react to avoid this obstacle like stopping and 
turning to any empty direction.
2. L293D is used to control the speed and the direction of motors.
3. LCD displays the current direction that car immediately move.
4. Servo is used to make ultrasonic scanning around 180°.
# Flow Chart 
![image](https://github.com/faatthy/Autonomous-car/assets/110846097/9a78efb2-7499-43a5-bd6f-dfd5578554a2)
