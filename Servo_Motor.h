/*
 * Servo_Motor.h
 *
 * Created: 11/19/2024 11:23:08 PM
 *  Author: Zyad Ayman
 */ 


#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_


#include "std_types.h"
#include "Utils.h"



void SERVO_vInit();
void SERVO_vRotateMotor(u8 u8ChannelOutput , s8 s8DegreesToRotate);




#endif /* SERVO_MOTOR_H_ */