/*
 * main.c
 *
 * Created: 15/11/2014 2:44:33 PM
 *  Author: Justin
 */ 

//Include libraries and dependencies
#define __AVR_ATxmega32C4__
#include <avr/io.h>

//TODO:: Make #defines for constants...
//Define constants

//Function headers
void init_uart(void);
void init_i2c(void);
void init_timers(void);

//***********************************************
int main(void)
{
	//Initialize clock source
	//TODO:: Wait until the 32Mhz internal oscillator is stable
	//while( !(OSC_STATUS & OSC_RC32MRDY_bm)); //Wait until the 32Mhz internal oscillator is stable
	//OSC_CTRL |= OSC_RC32MEN_bm; //Enable 32Mhz internal oscillator once it is stable
	//CLK_CTRL |= 0x01; //Select 32Mhz internal oscillator for CPU and peripheral operation
	
	//Enable runtime calibration (DFLL) of the main clock source
	//TODO:: Wait until the 32.768KHz internal oscillator is stable
	//while( !(OSC_STATUS & OSC_RC32KRDY_bm)); //Wait until the 32.768Khz internal oscillator is stable
	//OSC_CTRL |= OSC_RC32KEN_bm; //Enable 32.768Khz internal oscillator once it is stable
	//DFLLRC32M_CTRL |= DFLL_ENABLE_bm; //Enable DFLL now that the main clock and reference clock are enabled
	
	//Initialize all peripherals
	//init_uart();
	//init_i2c();
	//init_timers();
	
	//TCD0_CCA = 900;
	//TCD0_CCB = 1000;
	//TCD0_CCC = 1100;
	//TCD0_CCD = 1200;

    //TEST BLINK CODE
    PORTA_DIR=0x01; //PA[0] set to output
	
    while(1)
    {	
        //TEST BLINK CODE
        PORTA_OUT=0x00; //set PA[0] low
        for (int i=0; i<10000; i++);
        PORTA_OUT=0x01; //set PA[0] high
        for (int i=0; i<10000; i++);


		//Read input from XRF wireless module
		
		//Read input from IMU
		
		//Make calculations
		
		//Update registers and operating parameters
		
		//Change servo outputs
		/*
		TCD0_CCA = 900;
		TCD0_CCB = 1000;
		TCD0_CCC = 1100;
		TCD0_CCD = 1200;
		*/
		
    }
}
//***********************************************

//Function definitions

//VOID INIT_UART()
//Initialize UART port for communications with the XRF wireless module
void init_uart(void)
{
	
}

//VOID INIT_I2C()
//Initialize I2C for retrieving telemetry from the 9-axis inertial measurement unit (IMU)
void init_i2c(void)
{
	
}

//VOID INIT_TIMERS()
//Initialize timers to generate 4 PWM outputs for use with electronic speed controllers
void init_timers(void)
{
    /*
	//Configure port D for timer operation
	PORTD_DIR |= 0x0F; //PD[3..0] configured for timer output
	//Configure the timer control registers
	TCD0_CTRLA |= 0x03; //TCC0 is enabled by setting the prescaler to clk/64
	TCD0_CTRLB |= 0x03; //TCC0 group is configured to generate single-slope PWM
	TCD0_CTRLB |= 0xF0; //Enable all timer outputs (CCA,CCB,CCC,CCD)
	//Set the period
	TCD0_PER = 10000; //Equates to 50Hz when clk/64 prescaler is used with a clock frequency of 32Mhz
	//Set all motors to idle
	TCD0_CCA = 0;
	TCD0_CCB = 0;
	TCD0_CCC = 0;
	TCD0_CCD = 0;
    */
}
