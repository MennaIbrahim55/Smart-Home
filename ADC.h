/* 
 * File:   ADC.h
 * Author: Menna
 *
 * Created on July 5, 2025, 5:15 PM
 */

#ifndef ADC_H
#define	ADC_H



//define channels 
#define ADC_CH0    0
#define ADC_CH1    1
#define ADC_CH2    2
#define ADC_CH3    3
#define ADC_CH4    4
#define ADC_CH5    5
#define ADC_CH6    6
#define ADC_CH7    7



//#define prescalar   0
#define ADC_PS_2    1
#define ADC_PS_4    2
#define ADC_PS_8    3
#define ADC_PS_16   4
#define ADC_PS_32   5
#define ADC_PS_64   6
#define ADC_PS_128  7

//Reference Voltage
#define ADC_REF_AREF             0
#define ADC_REF_AVCC             1
#define ADC_REF_INTERNAL_2_56V   3

//Resolusion= Vin at(D=1) = 1*Vref/2^n-1= 5/1023 in mV
#define ADC_step 4.88758553275
/**
 * select CH,
 * select Freq,
 * select REF
 * ......>>> MODE 
 */
void init_ADC(char ADC_CH, char ADC_FREQ, char ADC_REF);
void ADC_enable();
void ADC_disable();

void ADC_select_CH(char ADC_CH);
void ADC_select_FREQ(char ADC_FREQ);
void ADC_select_REF(char ADC_REF);

void ADC_SC();
void ADC_wait();
int ADC_read_mV();

void ADC_INT_enable();

#endif	/* ADC_H */


