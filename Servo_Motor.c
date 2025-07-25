/*
 * Servo_Motor.c
 *
 * Created: 11/19/2024 11:22:51 PM
 *  Author: Zyad Ayman
 */

#include "Servo_Motor.h"
#include "PWM_Timer1.h"
#include "DIO.h"

/*
 * Function: SERVO_vInit
 * ---------------------
 * Initializes Timer1 in Fast PWM mode for controlling servo motors.
 */
void SERVO_vInit()
{
    // Initialize Fast PWM mode on Timer1 with ICR1 top
    PWM_vInit_T1_FastMode();
}

/*
 * Function: SERVO_vRotateMotor
 * ----------------------------
 * Rotates a servo motor connected to either OC1A or OC1B pin to a specific angle.
 *
 * Parameters:
 *   u8ChannelOutput - 'A' or 'B' to select OC1A or OC1B pin
 *   s8DegreesToRotate - Desired angle to rotate: supported values -90, -45, 0, +45, +90
 *
 * Notes:
 *   - For OC1A, PD5 is used.
 *   - For OC1B, PD4 is used.
 *   - PWM values are approximate based on a typical servo that responds to 1ms–2ms pulse widths.
 */
void SERVO_vRotateMotor(u8 u8ChannelOutput , s8 s8DegreesToRotate)
{
    if (u8ChannelOutput == 'A' || u8ChannelOutput == 'a')
    {
        // Channel OC1A
        DIO_vSet_Pin_Direction('d', PIN_NO_5 , OUTPUT);

        switch (s8DegreesToRotate)
        {
            case -90:
                PWM_vSetValue_OCR1A_T1_Manual(65);    // ~1ms pulse
                break;
            case -45:
                PWM_vSetValue_OCR1A_T1_Manual(120);   // ~1.25ms pulse
                break;
            case 0:
                PWM_vSetValue_OCR1A_T1_Manual(175);   // ~1.5ms pulse
                break;
            case 45:
                PWM_vSetValue_OCR1A_T1_Manual(240);   // ~1.75ms pulse
                break;
            case 90:
                PWM_vSetValue_OCR1A_T1_Manual(300);   // ~2ms pulse
                break;
        }
    }
    else if (u8ChannelOutput == 'B' || u8ChannelOutput == 'b')
    {
        // Channel OC1B
        DIO_vSet_Pin_Direction('d', PIN_NO_4 , OUTPUT);

        switch (s8DegreesToRotate)
        {
            case -90:
                PWM_vSetValue_OCR1B_T1_Manual(65);
                break;
            case -45:
                PWM_vSetValue_OCR1B_T1_Manual(120);
                break;
            case 0:
                PWM_vSetValue_OCR1B_T1_Manual(175);
                break;
            case 45:
                PWM_vSetValue_OCR1B_T1_Manual(240);
                break;
            case 90:
                PWM_vSetValue_OCR1B_T1_Manual(300);
                break;
        }
    }
}
