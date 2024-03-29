/***********************************************************************************************************
 ===========================================================================================================
 Module      :  pwm
 Author      :  AHMED ADLY
 date        :  26/2/2024
 Description :  PWM driver Source file for the ATmega32
 ===========================================================================================================
 ***********************************************************************************************************/
#include <avr/io.h>
#include "pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*Description:
 * The function responsible for trigger the Timer0 with the PWM Mode.
 * Setup the PWM mode with Non-Inverting.
 * Setup the prescaler with F_CPU/8.
 * Setup the compare value based on the required input duty cycle
 * Setup the direction for OC0 as output pin through the GPIO driver.
 * The generated PWM signal frequency will be 500Hz to control the DC Motor speed.
 */
void PWM_Timer0_init (void)
{
	TCNT0 = 0; // Set Timer Initial Value to 0
	GPIO_setupPinDirection(PWM_OUTPUT_PORT_ID, PWM_OUTPUT_PIN_ID, PIN_OUTPUT); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.
	/* configure the timer
		 * 1. Fast PWM mode FOC0=0
		 * 2. Fast PWM Mode WGM01=1 & WGM00=1
		 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
		 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
		 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01);
}

void PWM_Timer0_Start(uint8 duty_cycle)
{
	OCR0  = duty_cycle;

	TCCR0|=(1<<CS01);
}
