/*
 ============================================================================
 Name        : motor.h
 Module Name : MOTOR
 Author      : Ahmed Ali
 Date        : 10 Oct 2023
 Description : Header file for the motor driver
 ============================================================================
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "../../lib/std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	STOP, ANTI_CLOCK_WISE, CLOCK_Wise
} DcMotor_State;

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define MOTOR_PORTID		PORTB_ID
#define MOTOR_IN1_PINID		PIN0_ID
#define MOTOR_IN2_PINID		PIN1_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * 1. The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * 2. Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);

/*
 * Description :
 * 1. The function responsible for rotate the DC Motor CW/
 *    or A-CW or stop the motor based on the state input state value.
 * 2. Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State a_state, uint8 a_speed);

#endif /* MOTOR_H_ */
