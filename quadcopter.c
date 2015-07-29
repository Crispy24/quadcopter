/*
 * main.c
 *
 * Created: 15/11/2014
 * Author: Justin
 */ 

//Include libraries and dependencies
#define __AVR_ATxmega32C4__
#include <avr/io.h>

//TODO make #defines for constants...
//TODO ensure my defines are not duplicates from #included files
//Define constants
#define PORT_INPUT_PULLUP 0x18

//Function headers
void init_uart(void);
void init_i2c(void);
void init_timers(void);
void init_battery_monitor(void);

uint8_t check_battery(void);

//***********************************************
int main(void)
{
	//Initialize clock source
	//TODO Wait until the 32Mhz internal oscillator is stable
	//while( !(OSC_STATUS & OSC_RC32MRDY_bm)); //Wait until the 32Mhz internal oscillator is stable
	//OSC_CTRL |= OSC_RC32MEN_bm; //Enable 32Mhz internal oscillator once it is stable
	//CLK_CTRL |= 0x01; //Select 32Mhz internal oscillator for CPU and peripheral operation
	
	//Enable runtime calibration (DFLL) of the main clock source
	//TODO Wait until the 32.768KHz internal oscillator is stable
	//while( !(OSC_STATUS & OSC_RC32KRDY_bm)); //Wait until the 32.768Khz internal oscillator is stable
	//OSC_CTRL |= OSC_RC32KEN_bm; //Enable 32.768Khz internal oscillator once it is stable
	//DFLLRC32M_CTRL |= DFLL_ENABLE_bm; //Enable DFLL now that the main clock and reference clock are enabled
	
	//Initialize all peripherals
	//init_uart();
	//init_i2c();
	//init_timers();
    init_battery_monitor();
	
	//TCD0_CCA = 900;
	//TCD0_CCB = 1000;
	//TCD0_CCC = 1100;
	//TCD0_CCD = 1200;


    while(1)
    {
        //Check battery voltage TODO figure out how to track alarms and report
        check_battery();

		//Read input from XRF wireless module
		
		//Read input from IMU
		
		//Make flight calculations
		
		//Update registers and operating parameters for stable flight
		
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
//Initialize I2C for retrieving telemetry from the 9-axis inertial
//measurement unit (IMU)
void init_i2c(void)
{
	
}

//VOID INIT_TIMERS()
//Initialize timers to generate 4 PWM outputs for use with electronic
//speed controllers
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

/**
 * @desc - Initialize port R to monitor the low voltage indicator.
 *         The low voltage indicator is an open-drain output from
 *         the MCP6546. PR[0] will see a LOW when the battery
 *         voltage goes below 6.6VDC
 */
void init_battery_monitor(void)
{
    //Setup PR[0] to take input from the MCP6546
    //Set PR[0] as input
    PORTR_DIRCLR = PIN0_bm;
    //Apply a pull-up resistor on PR[0]
    PORTR_PIN0CTRL = PORT_INPUT_PULLUP & PORT_OPC_gm;
}

/**
 * @desc - Checks if the low battery voltage indicator is up
 *
 * @return uint8: 1 if alarm is up. 0 if not.
 */
uint8_t check_battery(void)
{
    //(PR[0] is 0 when alarm is set, 1 when alarm is clear)
    return (PORTR_IN & PIN0_bm) ^ PIN0_bm; //TODO ensure return value is correct
}
