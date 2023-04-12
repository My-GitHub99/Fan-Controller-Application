/*
 * test.c
 *
 *  Created on: Apr 5, 2023
 *      Author: ahmed bahaa
 */
#include "../std_types.h"
#include "../MCAL/GPIO/gpio.h"
#include "../MCAL/PWM/PWM.h"
#include "../HAL/Sensor/sensor.h"
#include "../HAL/Motor/motor.h"
#include "../HAL/LCD/lcd.h"
#include <util/delay.h> /* For the delay functions */

/*tests: GPIO,MOTOR,PWM modules*/
void TestMotor(void)
{
	DcMotor_Init();
		while(1)
		{
			DcMotor_Rotate(MOTOR_ON_CW,50);
			_delay_ms(1);
		}

}
/*tests: ADC,SENSOR,LCD*/
/*void testSensor(void)
{
	uint8 roomTemp=0;
	ADC_readChannel(SENSOR_CHANNEL_ID);
	roomTemp=LM35_getTemperature(&ADC_instance1);
	if(roomTemp >= 100)
			{
				LCD_intgerToString(roomTemp);
			}
			else
			{
				LCD_intgerToString(roomTemp);

				LCD_displayCharacter(' ');
			}
	    }*/




/*int main ()
{
ADC_init(&ADC_instance1);
LCD_init();
	for(;;)
	{
		LCD_moveCursor(1,4);
		testSensor();
	}
}*/
