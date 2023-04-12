/*
 * main.c
 *
 *  Created on: Apr 3, 2023
 *      Author: user
 */

#include "./HAL/Sensor/sensor.h"
#include "./HAL/Motor/motor.h"
#include "./HAL/LCD/lcd.h"

int main()
{
	uint8 roomTemperature=0;
	DcMotor_Init();
	LCD_init();
	LM35_init(&LM35_Sensor_instance);
	DcMotor_Rotate(MOTOR_OFF,0);
	uint8 flag=0;
	for(;;)
	{
		LCD_moveCursor(0,0);
		roomTemperature=LM35_getTemperature(&LM35_Sensor_instance);
		if(roomTemperature<30)
		 {
		  DcMotor_Rotate(MOTOR_OFF,0);
		  if(flag==0)
		  {
		  LCD_clearScreen();
		  flag=1;
		  }
		  LCD_displayString("FAN IS OFF");
		  		 }
		else if(roomTemperature>=30 && roomTemperature<60)
		 {
		  flag=0;
		  DcMotor_Rotate(MOTOR_ON_CW,25);
		  LCD_displayString("FAN IS ON - 25%");
		 }
		else if (roomTemperature>=60 && roomTemperature<90)
		 {
		  DcMotor_Rotate(MOTOR_ON_CW,50);
		  LCD_displayString("FAN IS ON - 50%");
		 }
		else if (roomTemperature>=90 && roomTemperature<120)
		 {
		  DcMotor_Rotate(MOTOR_ON_CW,75);
		  LCD_displayString("FAN IS ON - 75%");
		  LCD_displayCharacter(' ');
		  LCD_displayCharacter(' ');
		 }
		else if(roomTemperature>=120)
		 {
		  DcMotor_Rotate(MOTOR_ON_CW,100);
		  LCD_displayString("FAN IS ON - 100%");
		 }

		LCD_moveCursor(1,0);
		LCD_displayString("TEMP=");
		if(roomTemperature>= 100)
		 {
		  LCD_intgerToString(roomTemperature);
		 }
		 else
		 {
		  LCD_intgerToString(roomTemperature);
		  LCD_displayCharacter(' ');
		 }
	}

}
