/*
 * Timer_interface.h
 *
 *  Created on: Apr 18, 2025
 *      Author: kerel
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

typedef enum
{
    Timer0,
    Timer1,
    Timer2
}Timer_Timers;

/*This enumeration defines the modes of operation for timer 0 */
typedef enum
{
    Timer0_Normal,             /* Normal mode for Timer0 */
    Timer0_PWM_PhaseCorrect,   /* PWM Phase Correct mode for Timer0 */
    Timer0_CTC,                /*Clear Timer on Compare (CTC) mode for Timer0 */
    Timer0_FastPWM             /* Fast PWM mode for Timer0 */
}Timer0_Modes;

/*This enumeration defines the interrupts for timer 0*/
typedef enum
{
    Timer0_OVF,           /* Timer0 Overflow interrupt */
    Timer0_OCM            /* Timer0 Output Compare Match interrupt */
}Timer0_CFG;

/*Enumeration for Timer prescaler types*/
typedef enum
{
    Timer_NoClock,               /* No clock source (Timer/Counter stopped) */
    Timer_NoPrescaler,           /* No prescaling */
    Timer_Prescaler8,            /* clk/8 */
    Timer_Prescaler64,           /* clk/64 */
    Timer_Prescaler256,          /* clk/256 */
    Timer_Prescaler1024,         /* clk/1024 */
    Timer_ExtFalling,            /* External clock source on T0 pin, falling edge */
    Timer_ExtRising     ,         /* External clock source on T0 pin, rising edge */
}Timer_Scaler_Type;

void Timer0_Init(void);

/*The enable function for Timer0 for overflow mode
This function takes no parameters and returns an error status*/
void Timer0_OVF_Enable(void);
/*The disable function for Timer0 for overflow mode
This function takes no parameters and returns an error status*/
void Timer0_OVF_Disable(void);

/*The enable function for Timer0 for OutputCompareMatch  mode
This function takes no parameters and returns an error status*/
void Timer0_OCM_Enable(void);
/*The disable function for Timer0 for  OutputCompareMatch  mode
This function takes no parameters and returns an error status*/
void Timer0_OCM_Disable(void);

/*The configuration function for Timer0
This function takes the mode of operation and the prescaler value as parameters
and returns an error status*/

void Timer0_Config(Timer0_Modes Mode, Timer_Scaler_Type Scaler);

/*The set callback function for Timer0
This function takes a pointer to a function as a parameter and returns an error status
*/

void Timer0_SetCallBack(void (*TIMER0_App)(void));
/*The application function for Timer0
This function takes the mode of operation, the prescaler, time and the function  as parameters
and returns an error status*/
void Timer0_Application(Timer0_CFG Timer_timer0_cfg, Timer_Time time, void (*LocalPtr)(void));


/**
 * @brief Set the duty cycle for Timer 0 in Fast PWM mode.
 *
 * @param Copy_u8DutyCycle The desired duty cycle value.
 * @param Copy_u8PWMType The PWM type, which can be either INVERTED or NON_INVERTED.
 * @return TMR0_enuErrorStatus_t Error status of the duty cycle setting process.
 *
 * This function configures the duty cycle for TMR0 when operating in Fast PWM mode. The duty cycle and PWM type
 * are specified by the user. It returns an error status to indicate success or the nature of any failure in setting
 * the duty cycle.
 */
 void Timer0_enuSetDutyCycleFastPWM(uint8_t Copy_u8DutyCycle, uint8_t Copy_u8PWMType);

/**
 * @brief Set the duty cycle for Timer 0 in Phase Correct PWM mode.
 *
 * @param Copy_u8DutyCycle The desired duty cycle value.
 * @param Copy_u8PWMType The PWM type, which can be either INVERTED or NON_INVERTED.
 * @return TMR0_enuErrorStatus_t Error status of the duty cycle setting process.
 *
 * This function configures the duty cycle for TMR0 when operating in Phase Correct PWM mode. It allows
 * for finer control of the PWM waveform compared to Fast PWM mode. It returns an error status to indicate
 * the success or nature of any failure in setting the duty cycle.
 */
void Timer0_enuSetDutyCyclePhaseCorrection(uint8_t Copy_u8DutyCycle, uint8_t Copy_u8PWMType);



#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
