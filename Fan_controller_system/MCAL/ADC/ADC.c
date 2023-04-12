/*
 * adc.c
 *
 *  Created on: Apr 3, 2023
 *      Author: user
 */

/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "../../common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


void ADC_init(const ADC_ConfigType *Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 1* ADLAR   = 0 right adjusted
	 2* MUX4:0  = 00000 to choose channel 0 as initialization
	 3* REFS1:0 =
	              * external VREF       - 00 (0x00)
	              * AVCC 5V             - 01 (0x01)
	              * internal VREF 2.56V - 11 (0x03)
	 */
	switch(Config_Ptr->ADC_ReferenceVolatge)
	{
	case EXTERNAL_AREF:
	ADMUX |= (0x00<<REFS0);
	break;
	case AVCC:
	ADMUX |= (0x01<<REFS0);
	break;
	default:
	ADMUX |= (0x03<<REFS0);
	break;
	}

	/* ADCSRA Register Bits Description:
	 4* ADEN    = 1 Enable ADC
	 5* ADIE    = 0 Disable ADC Interrupt
	 6* ADATE   = 0 Disable Auto Trigger
     7* ADSP2:0 =
                 * No prescaler - 000
                 * division factor  2 - 001 (decimal 1)
                 * division factor  4 - 010 (decimal 2)
                 * division factor  8 - 011 (decimal 3)
                 * division factor 16 - 100(decimal 4)
                 * division factor 32 - 101(decimal 5)
                 * division factor 64 - 110 (decimal 6)
                 * division factor 128 - 111 (decimal 7)
        Note: AVR MC operates on frequency between 50-200 kHz */

	SET_BIT(ADCSRA,ADEN);
	switch(Config_Ptr->prescaler)
	{
	 case ADC_NO_PRESCALER :
		ADCSRA= (ADCSRA& 0xF8) | ADC_NO_PRESCALER;
		break;
	 case ADC_PRESCALER_2:
		ADCSRA= (ADCSRA& 0xF8) | ADC_PRESCALER_2;
		break;
	 case ADC_PRESCALER_4:
			ADCSRA= (ADCSRA& 0xF8) | ADC_PRESCALER_4;
			break;
	 case ADC_PRESCALER_8:
			ADCSRA= (ADCSRA& 0xF8) | ADC_PRESCALER_8;
			break;
	 case ADC_PRESCALER_16:
			ADCSRA= (ADCSRA& 0xF8) | ADC_PRESCALER_16;
			break;
	 case ADC_PRESCALER_32:
			ADCSRA= (ADCSRA& 0xF8) | ADC_PRESCALER_32;
			break;
	 case ADC_PRESCALER_64:
			ADCSRA= (ADCSRA& 0xF8) | ADC_PRESCALER_64;
			break;
	 case ADC_PRESCALER_128:
			ADCSRA= (ADCSRA& 0xF8) | ADC_PRESCALER_128;
			break;
	}
}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}







