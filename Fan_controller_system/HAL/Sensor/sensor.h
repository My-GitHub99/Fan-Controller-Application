/*
 * sensor.h
 *
 *  Created on: Apr 3, 2023
 *      Author: user
 */

#ifndef HAL_SENSOR_SENSOR_H_
#define HAL_SENSOR_SENSOR_H_

#include "../../std_types.h"
#include "../../MCAL/ADC/ADC.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         ADC_CHANNEL2_ID
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

extern ADC_ConfigType const LM35_Sensor_instance;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
void LM35_init(const ADC_ConfigType *Config_Ptr);
uint8 LM35_getTemperature(const ADC_ConfigType *Config_Ptr);

#endif /* LM35_SENSOR_H_ */


