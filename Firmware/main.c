/*
 CI-V Router is originally made by DJ0ABR (see: https://projects.dj0abr.de/doku.php?id=de:civrouter:civ_overview)
 Here it is adopted to use with AVR-GCC compiler and got some other changes in the configuration to work with "CI-V Router 2" project.
 "CI-V Router 2" is a device interacting with Wavelog and CI-V caompatible devices.
 
 2025-06-15 DK4DJ	Changed code to be compatible with AVR-GCC (tested version 5.4.0)
					Port handling fixed to send Broadcast packets to all Ports
					JTAG port disabled in software for use of PB4 and PB5
 */ 

#include <avr/io.h>
#include <main.h>


int main(void)
{
	// Der JTAG Port muss deaktiviert werden, da sonst die LEDs für Port CIV7 nicht verwendet werden können.
	CCP = CCP_IOREG_gc;			// Schutzmechanismus freischalten
	MCU.MCUCR = MCU_JTAGD_bm;	// JTAG deaktivieren
	
unsigned char n;

	// Interrupt system initialization
	// Make sure the interrupts are disabled
	cli(); //#asm("cli")
	// Low level interrupt: On
	// Round-robin scheduling for low level interrupt: Off
	// Medium level interrupt: On
	// High level interrupt: Off
	// The interrupt vectors will be placed at the start of the Application FLASH section
	n=(PMIC.CTRL & (~(PMIC_RREN_bm | PMIC_IVSEL_bm | PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm))) |
	PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm;
	CCP=CCP_IOREG_gc;
	PMIC.CTRL=n;
	// Set the default priority for round-robin scheduling
	PMIC.INTPRI=0x00;

	system_clocks_init();
	init_tx();
	ports_init();
	vports_init();
	usartc0_init();
	usartc1_init();
	usartd0_init();
	usartd1_init();
	usarte0_init();
	usarte1_init();
	usartf0_init();
	tcc0_init();
	
	// Globally enable interrupts
	sei(); //#asm("sei")

	PORTA.OUT = 0xff;   // LEDs off
	PORTB.OUT = 0xff;

	einschaltblinken();

	while (1)
	{
		read_civ();
		send_fifo();
		rs232_leds();
	}
}

