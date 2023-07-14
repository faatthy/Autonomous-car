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
