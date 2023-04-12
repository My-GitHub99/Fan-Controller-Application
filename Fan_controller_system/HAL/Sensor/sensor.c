/*
 * sensor.c
 *
 *  Created on: Apr 3, 2023
 *      Author: user
 */

#include "sensor.h"
#include "../../MCAL/ADC/ADC.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
ADC_ConfigType const LM35_Sensor_instance ={ADC_PRESCALER_8, AVCC};

void LM35_init(const ADC_ConfigType *Config_Ptr)
{
	 ADC_init(Config_Ptr);
}
uint8 LM35_getTemperature(const ADC_ConfigType *Config_Ptr)
{
	uint8 temp_value = 0;
	uint16 adc_value = 0;
	float32 ADC_Reference_Voltage_Value=Config_Ptr->ADC_ReferenceVolatge;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_Reference_Voltage_Value)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}
