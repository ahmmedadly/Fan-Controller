/***********************************************************************************************************
 ===========================================================================================================
 Module      :  DC motor
 Author      :  AHMED ADLY
 date        :  26/2/2024
 Description :  ATmega32 DC motor driver Source file
 ===========================================================================================================
 ***********************************************************************************************************/
#include "dc_motor.h"
#include "pwm.h"
#include "avr/io.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description :
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */

void DcMotor_init(void)

{
	PWM_Timer0_init();
	/* Configure the direction for DC motor pins */
	GPIO_setupPinDirection(MOTOR_PORT, MOTOR_INPUT1_PIN_ID	, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT, MOTOR_INPUT2_PIN_ID	, PIN_OUTPUT);

	/*Stop the DC motor at the beginning*/
	GPIO_writePort(MOTOR_PORT, STOP);
}

/*
 * Description:
 * The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	PWM_Timer0_Start (((uint16)(speed*255)/(100)));
	switch(state)
	{
	case STOP:
		GPIO_writePin(MOTOR_PORT, MOTOR_INPUT1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT, MOTOR_INPUT2_PIN_ID, LOGIC_LOW);
		break;

	case CW:
		GPIO_writePin(MOTOR_PORT, MOTOR_INPUT1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT, MOTOR_INPUT1_PIN_ID, LOGIC_HIGH);
		break;

	case ACW:
		GPIO_writePin(MOTOR_PORT, MOTOR_INPUT1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT, MOTOR_INPUT1_PIN_ID, LOGIC_LOW);
		break;
	}

	//PWM_Timer0_Start ((speed*2.55)); /* ((Speed*255)/100=duty cycle%)*/


}

