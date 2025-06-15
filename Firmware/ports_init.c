// I/O Registers definitions
#include <avr/io.h>

// Ports initialization
void ports_init(void)
{
	// PORTA initialization
	// OUT register
	PORTA.OUT=0x00;
	// Pin0: Output
	// Pin1: Output
	// Pin2: Output
	// Pin3: Output
	// Pin4: Output
	// Pin5: Output
	// Pin6: Output
	// Pin7: Output
	PORTA.DIR=0xFF;
	// Pin0 Output/Pull configuration: Totempole/No
	// Pin0 Input/Sense configuration: Sense both edges
	// Pin0 Inverted: Off
	// Pin0 Slew Rate Limitation: Off
	PORTA.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin1 Output/Pull configuration: Totempole/No
	// Pin1 Input/Sense configuration: Sense both edges
	// Pin1 Inverted: Off
	// Pin1 Slew Rate Limitation: Off
	PORTA.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin2 Output/Pull configuration: Totempole/No
	// Pin2 Input/Sense configuration: Sense both edges
	// Pin2 Inverted: Off
	// Pin2 Slew Rate Limitation: Off
	PORTA.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin3 Output/Pull configuration: Totempole/No
	// Pin3 Input/Sense configuration: Sense both edges
	// Pin3 Inverted: Off
	// Pin3 Slew Rate Limitation: Off
	PORTA.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin4 Output/Pull configuration: Totempole/No
	// Pin4 Input/Sense configuration: Sense both edges
	// Pin4 Inverted: Off
	// Pin4 Slew Rate Limitation: Off
	PORTA.PIN4CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin5 Output/Pull configuration: Totempole/No
	// Pin5 Input/Sense configuration: Sense both edges
	// Pin5 Inverted: Off
	// Pin5 Slew Rate Limitation: Off
	PORTA.PIN5CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin6 Output/Pull configuration: Totempole/No
	// Pin6 Input/Sense configuration: Sense both edges
	// Pin6 Inverted: Off
	// Pin6 Slew Rate Limitation: Off
	PORTA.PIN6CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin7 Output/Pull configuration: Totempole/No
	// Pin7 Input/Sense configuration: Sense both edges
	// Pin7 Inverted: Off
	// Pin7 Slew Rate Limitation: Off
	PORTA.PIN7CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Interrupt 0 level: Disabled
	// Interrupt 1 level: Disabled
	PORTA.INTCTRL=(PORTA.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
	// Pin0 Pin Change interrupt 0: Off
	// Pin1 Pin Change interrupt 0: Off
	// Pin2 Pin Change interrupt 0: Off
	// Pin3 Pin Change interrupt 0: Off
	// Pin4 Pin Change interrupt 0: Off
	// Pin5 Pin Change interrupt 0: Off
	// Pin6 Pin Change interrupt 0: Off
	// Pin7 Pin Change interrupt 0: Off
	PORTA.INT0MASK=0x00;
	// Pin0 Pin Change interrupt 1: Off
	// Pin1 Pin Change interrupt 1: Off
	// Pin2 Pin Change interrupt 1: Off
	// Pin3 Pin Change interrupt 1: Off
	// Pin4 Pin Change interrupt 1: Off
	// Pin5 Pin Change interrupt 1: Off
	// Pin6 Pin Change interrupt 1: Off
	// Pin7 Pin Change interrupt 1: Off
	PORTA.INT1MASK=0x00;

	// PORTB initialization
	// OUT register
	PORTB.OUT=0x00;
	// Pin0: Output
	// Pin1: Output
	// Pin2: Output
	// Pin3: Output
	// Pin4: Output
	// Pin5: Output
	// Pin6: Output
	// Pin7: Output
	PORTB.DIR=0xFF;
	// Pin0 Output/Pull configuration: Totempole/No
	// Pin0 Input/Sense configuration: Sense both edges
	// Pin0 Inverted: Off
	// Pin0 Slew Rate Limitation: Off
	PORTB.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin1 Output/Pull configuration: Totempole/No
	// Pin1 Input/Sense configuration: Sense both edges
	// Pin1 Inverted: Off
	// Pin1 Slew Rate Limitation: Off
	PORTB.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin2 Output/Pull configuration: Totempole/No
	// Pin2 Input/Sense configuration: Sense both edges
	// Pin2 Inverted: Off
	// Pin2 Slew Rate Limitation: Off
	PORTB.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin3 Output/Pull configuration: Totempole/No
	// Pin3 Input/Sense configuration: Sense both edges
	// Pin3 Inverted: Off
	// Pin3 Slew Rate Limitation: Off
	PORTB.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin4 Output/Pull configuration: Totempole/No
	// Pin4 Input/Sense configuration: Sense both edges
	// Pin4 Inverted: Off
	// Pin4 Slew Rate Limitation: Off
	PORTB.PIN4CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin5 Output/Pull configuration: Totempole/No
	// Pin5 Input/Sense configuration: Sense both edges
	// Pin5 Inverted: Off
	// Pin5 Slew Rate Limitation: Off
	PORTB.PIN5CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin6 Output/Pull configuration: Totempole/No
	// Pin6 Input/Sense configuration: Sense both edges
	// Pin6 Inverted: Off
	// Pin6 Slew Rate Limitation: Off
	PORTB.PIN6CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin7 Output/Pull configuration: Totempole/No
	// Pin7 Input/Sense configuration: Sense both edges
	// Pin7 Inverted: Off
	// Pin7 Slew Rate Limitation: Off
	PORTB.PIN7CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Interrupt 0 level: Disabled
	// Interrupt 1 level: Disabled
	PORTB.INTCTRL=(PORTB.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
	// Pin0 Pin Change interrupt 0: Off
	// Pin1 Pin Change interrupt 0: Off
	// Pin2 Pin Change interrupt 0: Off
	// Pin3 Pin Change interrupt 0: Off
	// Pin4 Pin Change interrupt 0: Off
	// Pin5 Pin Change interrupt 0: Off
	// Pin6 Pin Change interrupt 0: Off
	// Pin7 Pin Change interrupt 0: Off
	PORTB.INT0MASK=0x00;
	// Pin0 Pin Change interrupt 1: Off
	// Pin1 Pin Change interrupt 1: Off
	// Pin2 Pin Change interrupt 1: Off
	// Pin3 Pin Change interrupt 1: Off
	// Pin4 Pin Change interrupt 1: Off
	// Pin5 Pin Change interrupt 1: Off
	// Pin6 Pin Change interrupt 1: Off
	// Pin7 Pin Change interrupt 1: Off
	PORTB.INT1MASK=0x00;

	// PORTC initialization
	// OUT register
	PORTC.OUT=0x88;
	// Pin0: Input
	// Pin1: Input
	// Pin2: Input
	// Pin3: Output
	// Pin4: Input
	// Pin5: Input
	// Pin6: Input
	// Pin7: Output
	PORTC.DIR=0x88;
	// Pin0 Output/Pull configuration: Totempole/No
	// Pin0 Input/Sense configuration: Sense both edges
	// Pin0 Inverted: Off
	// Pin0 Slew Rate Limitation: Off
	PORTC.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin1 Output/Pull configuration: Totempole/No
	// Pin1 Input/Sense configuration: Sense both edges
	// Pin1 Inverted: Off
	// Pin1 Slew Rate Limitation: Off
	PORTC.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin2 Output/Pull configuration: Totempole/No
	// Pin2 Input/Sense configuration: Sense both edges
	// Pin2 Inverted: Off
	// Pin2 Slew Rate Limitation: Off
	PORTC.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin3 Output/Pull configuration: Totempole/No
	// Pin3 Input/Sense configuration: Sense both edges
	// Pin3 Inverted: Off
	// Pin3 Slew Rate Limitation: Off
	PORTC.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin4 Output/Pull configuration: Totempole/No
	// Pin4 Input/Sense configuration: Sense both edges
	// Pin4 Inverted: Off
	// Pin4 Slew Rate Limitation: Off
	PORTC.PIN4CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin5 Output/Pull configuration: Totempole/No
	// Pin5 Input/Sense configuration: Sense both edges
	// Pin5 Inverted: Off
	// Pin5 Slew Rate Limitation: Off
	PORTC.PIN5CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin6 Output/Pull configuration: Totempole/No
	// Pin6 Input/Sense configuration: Sense both edges
	// Pin6 Inverted: Off
	// Pin6 Slew Rate Limitation: Off
	PORTC.PIN6CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin7 Output/Pull configuration: Totempole/No
	// Pin7 Input/Sense configuration: Sense both edges
	// Pin7 Inverted: Off
	// Pin7 Slew Rate Limitation: Off
	PORTC.PIN7CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Interrupt 0 level: Disabled
	// Interrupt 1 level: Disabled
	PORTC.INTCTRL=(PORTC.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
	// Pin0 Pin Change interrupt 0: Off
	// Pin1 Pin Change interrupt 0: Off
	// Pin2 Pin Change interrupt 0: Off
	// Pin3 Pin Change interrupt 0: Off
	// Pin4 Pin Change interrupt 0: Off
	// Pin5 Pin Change interrupt 0: Off
	// Pin6 Pin Change interrupt 0: Off
	// Pin7 Pin Change interrupt 0: Off
	PORTC.INT0MASK=0x00;
	// Pin0 Pin Change interrupt 1: Off
	// Pin1 Pin Change interrupt 1: Off
	// Pin2 Pin Change interrupt 1: Off
	// Pin3 Pin Change interrupt 1: Off
	// Pin4 Pin Change interrupt 1: Off
	// Pin5 Pin Change interrupt 1: Off
	// Pin6 Pin Change interrupt 1: Off
	// Pin7 Pin Change interrupt 1: Off
	PORTC.INT1MASK=0x00;

	// PORTD initialization
	// OUT register
	PORTD.OUT=0x88;
	// Pin0: Input
	// Pin1: Input
	// Pin2: Input
	// Pin3: Output
	// Pin4: Input
	// Pin5: Input
	// Pin6: Input
	// Pin7: Output
	PORTD.DIR=0x88;
	// Pin0 Output/Pull configuration: Totempole/No
	// Pin0 Input/Sense configuration: Sense both edges
	// Pin0 Inverted: Off
	// Pin0 Slew Rate Limitation: Off
	PORTD.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin1 Output/Pull configuration: Totempole/No
	// Pin1 Input/Sense configuration: Sense both edges
	// Pin1 Inverted: Off
	// Pin1 Slew Rate Limitation: Off
	PORTD.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin2 Output/Pull configuration: Totempole/No
	// Pin2 Input/Sense configuration: Sense both edges
	// Pin2 Inverted: Off
	// Pin2 Slew Rate Limitation: Off
	PORTD.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin3 Output/Pull configuration: Totempole/No
	// Pin3 Input/Sense configuration: Sense both edges
	// Pin3 Inverted: Off
	// Pin3 Slew Rate Limitation: Off
	PORTD.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin4 Output/Pull configuration: Totempole/No
	// Pin4 Input/Sense configuration: Sense both edges
	// Pin4 Inverted: Off
	// Pin4 Slew Rate Limitation: Off
	PORTD.PIN4CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin5 Output/Pull configuration: Totempole/No
	// Pin5 Input/Sense configuration: Sense both edges
	// Pin5 Inverted: Off
	// Pin5 Slew Rate Limitation: Off
	PORTD.PIN5CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin6 Output/Pull configuration: Totempole/No
	// Pin6 Input/Sense configuration: Sense both edges
	// Pin6 Inverted: Off
	// Pin6 Slew Rate Limitation: Off
	PORTD.PIN6CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin7 Output/Pull configuration: Totempole/No
	// Pin7 Input/Sense configuration: Sense both edges
	// Pin7 Inverted: Off
	// Pin7 Slew Rate Limitation: Off
	PORTD.PIN7CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Interrupt 0 level: Disabled
	// Interrupt 1 level: Disabled
	PORTD.INTCTRL=(PORTD.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
	// Pin0 Pin Change interrupt 0: Off
	// Pin1 Pin Change interrupt 0: Off
	// Pin2 Pin Change interrupt 0: Off
	// Pin3 Pin Change interrupt 0: Off
	// Pin4 Pin Change interrupt 0: Off
	// Pin5 Pin Change interrupt 0: Off
	// Pin6 Pin Change interrupt 0: Off
	// Pin7 Pin Change interrupt 0: Off
	PORTD.INT0MASK=0x00;
	// Pin0 Pin Change interrupt 1: Off
	// Pin1 Pin Change interrupt 1: Off
	// Pin2 Pin Change interrupt 1: Off
	// Pin3 Pin Change interrupt 1: Off
	// Pin4 Pin Change interrupt 1: Off
	// Pin5 Pin Change interrupt 1: Off
	// Pin6 Pin Change interrupt 1: Off
	// Pin7 Pin Change interrupt 1: Off
	PORTD.INT1MASK=0x00;

	// PORTE initialization
	// OUT register
	PORTE.OUT=0x88;
	// Pin0: Input
	// Pin1: Input
	// Pin2: Input
	// Pin3: Output
	// Pin4: Input
	// Pin5: Input
	// Pin6: Input
	// Pin7: Output
	PORTE.DIR=0x88;
	// Pin0 Output/Pull configuration: Totempole/No
	// Pin0 Input/Sense configuration: Sense both edges
	// Pin0 Inverted: Off
	// Pin0 Slew Rate Limitation: Off
	PORTE.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin1 Output/Pull configuration: Totempole/No
	// Pin1 Input/Sense configuration: Sense both edges
	// Pin1 Inverted: Off
	// Pin1 Slew Rate Limitation: Off
	PORTE.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin2 Output/Pull configuration: Totempole/No
	// Pin2 Input/Sense configuration: Sense both edges
	// Pin2 Inverted: Off
	// Pin2 Slew Rate Limitation: Off
	PORTE.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin3 Output/Pull configuration: Totempole/No
	// Pin3 Input/Sense configuration: Sense both edges
	// Pin3 Inverted: Off
	// Pin3 Slew Rate Limitation: Off
	PORTE.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin4 Output/Pull configuration: Totempole/No
	// Pin4 Input/Sense configuration: Sense both edges
	// Pin4 Inverted: Off
	// Pin4 Slew Rate Limitation: Off
	PORTE.PIN4CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin5 Output/Pull configuration: Totempole/No
	// Pin5 Input/Sense configuration: Sense both edges
	// Pin5 Inverted: Off
	// Pin5 Slew Rate Limitation: Off
	PORTE.PIN5CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin6 Output/Pull configuration: Totempole/No
	// Pin6 Input/Sense configuration: Sense both edges
	// Pin6 Inverted: Off
	// Pin6 Slew Rate Limitation: Off
	PORTE.PIN6CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin7 Output/Pull configuration: Totempole/No
	// Pin7 Input/Sense configuration: Sense both edges
	// Pin7 Inverted: Off
	// Pin7 Slew Rate Limitation: Off
	PORTE.PIN7CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Interrupt 0 level: Disabled
	// Interrupt 1 level: Disabled
	PORTE.INTCTRL=(PORTE.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
	// Pin0 Pin Change interrupt 0: Off
	// Pin1 Pin Change interrupt 0: Off
	// Pin2 Pin Change interrupt 0: Off
	// Pin3 Pin Change interrupt 0: Off
	// Pin4 Pin Change interrupt 0: Off
	// Pin5 Pin Change interrupt 0: Off
	// Pin6 Pin Change interrupt 0: Off
	// Pin7 Pin Change interrupt 0: Off
	PORTE.INT0MASK=0x00;
	// Pin0 Pin Change interrupt 1: Off
	// Pin1 Pin Change interrupt 1: Off
	// Pin2 Pin Change interrupt 1: Off
	// Pin3 Pin Change interrupt 1: Off
	// Pin4 Pin Change interrupt 1: Off
	// Pin5 Pin Change interrupt 1: Off
	// Pin6 Pin Change interrupt 1: Off
	// Pin7 Pin Change interrupt 1: Off
	PORTE.INT1MASK=0x00;

	// PORTF initialization
	// OUT register
	PORTF.OUT=0x08;
	// Pin0: Input
	// Pin1: Input
	// Pin2: Input
	// Pin3: Output
	// Pin4: Input
	// Pin5: Input
	// Pin6: Input
	// Pin7: Input
	PORTF.DIR=0x08;
	// Pin0 Output/Pull configuration: Totempole/No
	// Pin0 Input/Sense configuration: Sense both edges
	// Pin0 Inverted: Off
	// Pin0 Slew Rate Limitation: Off
	PORTF.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin1 Output/Pull configuration: Totempole/No
	// Pin1 Input/Sense configuration: Sense both edges
	// Pin1 Inverted: Off
	// Pin1 Slew Rate Limitation: Off
	PORTF.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin2 Output/Pull configuration: Totempole/No
	// Pin2 Input/Sense configuration: Sense both edges
	// Pin2 Inverted: Off
	// Pin2 Slew Rate Limitation: Off
	PORTF.PIN2CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin3 Output/Pull configuration: Totempole/No
	// Pin3 Input/Sense configuration: Sense both edges
	// Pin3 Inverted: Off
	// Pin3 Slew Rate Limitation: Off
	PORTF.PIN3CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin4 Output/Pull configuration: Totempole/No
	// Pin4 Input/Sense configuration: Sense both edges
	// Pin4 Inverted: Off
	// Pin4 Slew Rate Limitation: Off
	PORTF.PIN4CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin5 Output/Pull configuration: Totempole/No
	// Pin5 Input/Sense configuration: Sense both edges
	// Pin5 Inverted: Off
	// Pin5 Slew Rate Limitation: Off
	PORTF.PIN5CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin6 Output/Pull configuration: Totempole/No
	// Pin6 Input/Sense configuration: Sense both edges
	// Pin6 Inverted: Off
	// Pin6 Slew Rate Limitation: Off
	PORTF.PIN6CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin7 Output/Pull configuration: Totempole/No
	// Pin7 Input/Sense configuration: Sense both edges
	// Pin7 Inverted: Off
	// Pin7 Slew Rate Limitation: Off
	PORTF.PIN7CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Interrupt 0 level: Disabled
	// Interrupt 1 level: Disabled
	PORTF.INTCTRL=(PORTF.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
	// Pin0 Pin Change interrupt 0: Off
	// Pin1 Pin Change interrupt 0: Off
	// Pin2 Pin Change interrupt 0: Off
	// Pin3 Pin Change interrupt 0: Off
	// Pin4 Pin Change interrupt 0: Off
	// Pin5 Pin Change interrupt 0: Off
	// Pin6 Pin Change interrupt 0: Off
	// Pin7 Pin Change interrupt 0: Off
	PORTF.INT0MASK=0x00;
	// Pin0 Pin Change interrupt 1: Off
	// Pin1 Pin Change interrupt 1: Off
	// Pin2 Pin Change interrupt 1: Off
	// Pin3 Pin Change interrupt 1: Off
	// Pin4 Pin Change interrupt 1: Off
	// Pin5 Pin Change interrupt 1: Off
	// Pin6 Pin Change interrupt 1: Off
	// Pin7 Pin Change interrupt 1: Off
	PORTF.INT1MASK=0x00;

	// PORTR initialization
	// OUT register
	PORTR.OUT=0x00;
	// Pin0: Input
	// Pin1: Input
	PORTR.DIR=0x00;
	// Pin0 Output/Pull configuration: Totempole/No
	// Pin0 Input/Sense configuration: Sense both edges
	// Pin0 Inverted: Off
	// Pin0 Slew Rate Limitation: Off
	PORTR.PIN0CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Pin1 Output/Pull configuration: Totempole/No
	// Pin1 Input/Sense configuration: Sense both edges
	// Pin1 Inverted: Off
	// Pin1 Slew Rate Limitation: Off
	PORTR.PIN1CTRL=PORT_OPC_TOTEM_gc | PORT_ISC_BOTHEDGES_gc;
	// Interrupt 0 level: Disabled
	// Interrupt 1 level: Disabled
	PORTR.INTCTRL=(PORTR.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_OFF_gc;
	// Pin0 Pin Change interrupt 0: Off
	// Pin1 Pin Change interrupt 0: Off
	PORTR.INT0MASK=0x00;
	// Pin0 Pin Change interrupt 1: Off
	// Pin1 Pin Change interrupt 1: Off
	PORTR.INT1MASK=0x00;
}

// Virtual Ports initialization
void vports_init(void)
{
	// PORTA mapped to VPORT0
	// PORTB mapped to VPORT1
	PORTCFG.VPCTRLA=PORTCFG_VP1MAP_PORTB_gc | PORTCFG_VP0MAP_PORTA_gc;
	// PORTC mapped to VPORT2
	// PORTD mapped to VPORT3
	PORTCFG.VPCTRLB=PORTCFG_VP3MAP_PORTD_gc | PORTCFG_VP2MAP_PORTC_gc;
}

