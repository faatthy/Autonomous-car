/*
 * main.c
 *
 *  Created on: Jun 25, 2023
 *      Author: fathy
 */
#include "../LIBRARY/errorState.h"
#include"../LIBRARY/stdTypes.h"
#include"../MCAL/DIO/DIO_int.h"

#include"../HAL/LCD/LCD_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/TIMER0/TIMER0_int.h"
#include"../HAL/SERVO_MOTOR/SERVO_MOTOR_int.h"
#include "../HAL/ULTRASONIC_SENSOR/ULTRASONIC_SENSOR_int.h"
#include "../HAL/MOTORS_CAR/MOTORS_CAR_int.h"

#include<util/delay.h>
enum state
{
	Forward,
	Right,
	Left,
	Back
}states;
u16 Mid_Distance;
u16 Right_Distance;
u16 Left_Distance;
int main(){
	LCD_voidInit();
	EXTI_voidInit();
	SERVO_MOTOR_voidInit();
	ULTRASONIC_SENSOR_voidInit();
	MOTORS_CAR_voidInit();
	Mid_Distance=ULTRASONIC_SENSOR_u16ReadDistance();
	LCD_voidWriteString("Autonomous car ");
	LCD_voidGoToPosition(1,0);
	LCD_voidWriteString("      IS ON");
	_delay_ms(2000);
	states=Forward;
	while(1){
		LCD_voidClearScreen();
		switch(states){
		case Forward:
			LCD_voidWriteString("FORWARD ");
			SERVO_MOTOR_voidRotateMiddle();
			Mid_Distance=ULTRASONIC_SENSOR_u16ReadDistance();
			if(Mid_Distance<=40&&Mid_Distance>0){
				MOTORS_CAR_voidStop();
				SERVO_MOTOR_voidRotateRight();
				_delay_ms(1000);
				Right_Distance=ULTRASONIC_SENSOR_u16ReadDistance();
				_delay_ms(1000);
				SERVO_MOTOR_voidRotateLeft();
				_delay_ms(1000);
				Left_Distance=ULTRASONIC_SENSOR_u16ReadDistance();
				_delay_ms(1000);
				if(Right_Distance>40||Right_Distance==0){
					states=Right;
				}
				else if (Left_Distance>40||Left_Distance==0){
					states=Left;
				}
				else{
					states=Back;
				}
			}
			else{
				MOTORS_CAR_voidForward();
			}
			break;
		case Right:
			LCD_voidWriteString("RIGHT");
			MOTORS_CAR_voidRight();
			_delay_ms(1000);
			MOTORS_CAR_voidStop();
			SERVO_MOTOR_voidRotateMiddle();
			_delay_ms(1000);
			states=Forward;
			break;
		case Left:
			LCD_voidWriteString("LEFT");
			MOTORS_CAR_voidLeft();
			_delay_ms(1000);
			MOTORS_CAR_voidStop();
			SERVO_MOTOR_voidRotateMiddle();
			_delay_ms(1000);
			states=Forward;
			break;
		case Back:
			LCD_voidWriteString("BACKWARD");
			MOTORS_CAR_voidBackward();
			_delay_ms(1000);
			MOTORS_CAR_voidStop();
			SERVO_MOTOR_voidRotateRight();
			_delay_ms(1000);
			Right_Distance=ULTRASONIC_SENSOR_u16ReadDistance();
			_delay_ms(1000);
			SERVO_MOTOR_voidRotateLeft();
			_delay_ms(1000);
			Left_Distance=ULTRASONIC_SENSOR_u16ReadDistance();
			_delay_ms(1000);
			if(Right_Distance>40||Right_Distance==0){
				states=Right;
				}
			else if (Left_Distance>40||Left_Distance==0){

				states=Left;
				}
				else{
				states=Back;
				}
			break;

		}

	}

}
