/*
 * Timer.c
 *
 *  Created on: Apr 18, 2025
 *      Author: kerel
 */
#include <Timer/Timer_interface.h>
#include <Timer/Timer_private.h>

void Timer0_Init(void) {

}

void Timer0_Config(Timer0_Modes Mode, Timer_Scaler_Type Scaler) {

	//Timer0_Normal,             /* Normal mode for Timer0 */
	//Timer0_PWM_PhaseCorrect,   /* PWM Phase Correct mode for Timer0 */
	//Timer0_CTC,                /*Clear Timer on Compare (CTC) mode for Timer0 */
	//Timer0_FastPWM

	// Write WGM01 WGM00 into TCCR0
	WRITE_BIT(TCCR0, WGM00, GET_BIT(Mode,0));
	WRITE_BIT(TCCR0, WGM01, GET_BIT(Mode,1));

	// Clear CS02 CS01 CS00
	TCCR0 &= 0b11111000;
	// Write Scaler into (CS02,CS01,CS00) in TCCR0
	TCCR0 |= (Scaler & 0b00000111);
}

void Timer0_OVF_Enable(void) {
	// Timer/Counter0 Overflow Interrupt Enable
	SET_BIT(TIMSK, TOIE0);
}
void Timer0_OVF_Disable(void) {
	// Timer/Counter0 Overflow Interrupt Disable
	CLEAR_BIT(TIMSK, TOIE0);
}
void Timer0_OCM_Enable(void) {
	// Timer/Counter0 Output Compare Match Interrupt Enable
	SET_BIT(TIMSK, OCIE0);
}
void Timer0_OCM_Disable(void) {
	// Timer/Counter0 Output Compare Match Interrupt Disable
	CLEAR_BIT(TIMSK, OCIE0);
}

void Timer0_SetDutyCycleFastPWM(uint8 DutyCycle, PWM_Signal_Type PWMType) {
	volatile uint8 OCR = 0;
	switch (PWMType) {
	case NonInververted:
		OCR = ((256 * DutyCycle) / 100) - 1;
		break;

	case Inververted:
		OCR = ((256 * (100 - DutyCycle)) / 100) - 1;
		break;
	}

	OCR0 = OCR;
}

void Timer0_SetDutyCyclePhaseCorrection(uint8 DutyCycle,
		PWM_Signal_Type PWMType) {
	volatile uint8 OCR = 0;
	switch (PWMType) {
	case NonInververted:
		OCR = (((510 / 2) * DutyCycle) / 100) - 1;
		break;

	case Inververted:
		OCR = (((510 / 2) * (100 - DutyCycle)) / 100) - 1;
		break;
	}

	OCR0 = OCR;
}

ISR(TIMER0_COMP_vect) {

}

ISR(TIMER0_OVF_vect) {
}
