/*
 * interrupts.h
 *
 * Created: 10/10/2019 6:34:31 PM
 *  Author: sshe325
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "uart.h"
#include "adc.h"
#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <avr/iom8.h>
#include <avr/interrupt.h>

#define STOPCYCLE 100

ISR(TIMER1_COMPA_vect); //interrupt to handle T/4 or 3T/4 time crossing
ISR(TIMER1_COMPB_vect); //interrupt to handle T or T/2 time crossing
ISR(TIMER2_COMP_vect); //PWM duty cycle expired, shut off signal
ISR(TIMER2_OVF_vect); //PWM restarted, change switches according to current current direction

volatile unsigned int t2; //flag to check if T/2 is next time crossing to be handled
volatile unsigned int stop_counter; //flag to count cycles and see if we are going to stop the motor to measure backemf
volatile unsigned int data_received; //flag to indicate to main that data has been recieved

volatile unsigned int voltage_left_on; //flag to indicate if the left side of the motor is currently in the PWM ON state
volatile unsigned int voltage_right_on; //flag to indicate if the right side of the motor is currently in the PWM ON state
volatile unsigned int timer0_ovf_count; //keeps track of how many times timer0 has overflown
volatile unsigned int current_i; //current adc reading index
volatile unsigned int backemf_i; //backemf adc reading index
volatile unsigned int backemffound; //flag to indicate if backemf frequency was found last time
volatile uint64_t backemffreq; //back emf frequency
volatile uint64_t backemftime; //back emf time 

char* str_buffer; //string buffer to receive data

volatile unsigned char received_char;

#endif /* INTERRUPTS_H_ */