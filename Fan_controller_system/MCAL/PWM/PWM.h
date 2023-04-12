/*
 * PWM.h
 *
 *  Created on: Apr 3, 2023
 *      Author: user
 */

#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_

#include "../../std_types.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initializing and starting Timer0 PWM signal .
 * it takes the desired duty cycle for the PWM output signal
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* MCAL_PWM_PWM_H_ */
