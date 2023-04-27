/*
 * adc.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Ahmed Bahaa
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "../../std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NUM_OF_ADC_CHANNELS 8

/*ADC CHANNELS - 8 CHANNELS*/
#define ADC_CHANNEL0_ID   0
#define ADC_CHANNEL1_ID   1
#define ADC_CHANNEL2_ID   2
#define ADC_CHANNEL3_ID   3
#define ADC_CHANNEL4_ID   4
#define ADC_CHANNEL5_ID   5
#define ADC_CHANNEL6_ID   6
#define ADC_CHANNEL7_ID   7

#define ADC_MAXIMUM_VALUE    1023 /*10 bit resolution*/

/*Prescaler values*/
#define ADC_NO_PRESCALER     0
#define ADC_PRESCALER_2      1
#define ADC_PRESCALER_4      2
#define ADC_PRESCALER_8      3
#define ADC_PRESCALER_16     4
#define ADC_PRESCALER_32     5
#define ADC_PRESCALER_64     6
#define ADC_PRESCALER_128    7

/* Voltage Reference Musks*/
#define EXTERNAL_AREF        3UL /*external Voltage */
#define AVCC                 5UL /* 5 VCC VOLT*/
#define INTERNAL_VOLTAGE     2.56F /*2.56 Internal Reference VOLT*/
/*******************************************************************************
 *                               Types Definitions                                  *
 *******************************************************************************/

typedef struct ADC_ConfigType{
	uint8 prescaler;
	uint8 ADC_ReferenceVolatge;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 * it takes the required pre-scaler value for setting the ADC
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */

