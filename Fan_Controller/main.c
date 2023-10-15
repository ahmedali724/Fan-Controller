/*
 ============================================================================
 Name        : main.c
 Module Name : APP
 Author      : Ahmed Ali
 Date        : 10 Oct 2023
 Description : The main function
 ============================================================================
 */

#include "HAL/LCD/lcd.h" /* To use LCD functions */
#include "HAL/MOTOR/motor.h" /* To use MOTOR functions */
#include "HAL/TEMPERATURE SENSOR/lm35_sensor.h" /* To use LM35 Functions */
#include "MCAL/ADC/adc.h" /* To use init function of ADC */
#include "MCAL/TIMER0_PWM/timer0_pwm.h" /* To use init function of PWM */

int main(void)
{
	/* Configuration and initialization functions */
	ADC_ConfigType ADC_config =
	{ INTERNAL_REFERENCE, PRESCALER_8 };
	LCD_init();
	DcMotor_Init();
	PWM_Timer0_init();
	ADC_init(&ADC_config);
	/* Print the main strings of project in the 2*16 LCD */
	LCD_displayString("    FAN is");
	LCD_moveCursor(1, 0);
	LCD_displayString("    TEMP =    C");
	uint8 tempValue = 0;
	while (1)
	{
		/* Get the digital value of LM35 sensor form the ADC
		 * print state and temperature with LCD display string function
		 * send duty cycle to DC motor function
		 */
		tempValue = LM35_getTemperature();
		if (tempValue < 30)
		{
			/* If the temperature is less than 30C turn off the fan */
			LCD_displayStringRowColumn(0, 11, "OFF");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(tempValue);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(STOP, 0);
		}
		else if (tempValue < 60)
		{
			/* If the temperature is greater than or equal 30C turn on the fan
			 * with 25% of its maximum speed
			 */
			LCD_displayStringRowColumn(0, 11, "ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 11);
			LCD_intgerToString(tempValue);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CLOCK_Wise, 25);
		}
		else if (tempValue < 90)
		{
			/* If the temperature is greater than or equal 60C turn on the fan
			 * with 50% of its maximum speed
			 */
			LCD_displayStringRowColumn(0, 11, "ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 11);
			LCD_intgerToString(tempValue);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CLOCK_Wise, 50);
		}
		else if (tempValue < 120)
		{
			/* If the temperature is greater than or equal 90C turn on the fan
			 * with 75% of its maximum speed
			 */
			LCD_displayStringRowColumn(0, 11, "ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 11);
			LCD_intgerToString(tempValue);
			/* This if condition to ensure that the third digit
			 * is not excited in numbers less than 100
			 */
			if (tempValue < 100)
			{
				LCD_displayCharacter(' ');
			}
			DcMotor_Rotate(CLOCK_Wise, 75);
		}
		else
		{
			/* If the temperature is greater than or equal 120C turn on the fan
			 *  with 100% of its maximum speed
			 */
			LCD_displayStringRowColumn(0, 11, "ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 11);
			LCD_intgerToString(tempValue);
			DcMotor_Rotate(CLOCK_Wise, 100);
		}
	}
}
