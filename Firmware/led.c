#include <main.h>
#include <util/delay.h>

// LED Status:
// 0=aus
// LEDONTIME=wird eingeschaltet und gleich runtergezählt
// >0 brennt und wird bis 0 runtergezählt, beim Übergang 1->0 ausgeschaltet
uint8_t ledgn_state[8] = {0,0,0,0,0,0,0,0};
uint8_t ledrd_state[8] = {0,0,0,0,0,0,0,0};

uint8_t rxled_bits[8] =
{
	0,
	2,
	4,
	6,
	0,
	2,
	4,
	6
};

uint8_t txled_bits[8] =
{
	1,
	3,
	5,
	7,
	1,
	3,
	5,
	7,
};

// porta=0, portb=1
uint8_t led_port[8] =
{
	0,
	0,
	0,
	0,
	1,
	1,
	1,
	1
};

// schalte die grüne, zum CIV Kanal gehörende, LED ein/aus
// nur im Hauptprogramm aufrufen
void led_rx(uint8_t civ)
{
	ledgn_state[civ] = LEDONTIME_GN;
}

void led_tx(uint8_t civ)
{
	ledrd_state[civ] = LEDONTIME_RD;
}

// nur im timer IRQ aufrufen !
void switch_rxled(uint8_t civ, uint8_t onoff)
{
	if(led_port[civ] == 0)
	{
		if(onoff)
		PORTA.OUTCLR = 1 << rxled_bits[civ];
		else
		PORTA.OUTSET = 1 << rxled_bits[civ];
	}
	
	if(led_port[civ] == 1)
	{
		if(onoff)
		PORTB.OUTCLR = 1 << rxled_bits[civ];
		else
		PORTB.OUTSET = 1 << rxled_bits[civ];
	}
}

void switch_txled(uint8_t civ, uint8_t onoff)
{
	if(led_port[civ] == 0)
	{
		if(onoff)
		PORTA.OUTCLR = 1 << txled_bits[civ];
		else
		PORTA.OUTSET = 1 << txled_bits[civ];
	}
	
	if(led_port[civ] == 1)
	{
		if(onoff)
		PORTB.OUTCLR = 1 << txled_bits[civ];
		else
		PORTB.OUTSET = 1 << txled_bits[civ];
	}
}

// Aufruf alle 2ms aus dem Timer IRQ
void handle_leds()
{
	uint8_t civ;

	for(civ=CIV1; civ<=RS232; civ++)
	{
		// grüne RX LEDs
		if(ledgn_state[civ] == LEDONTIME_GN)
		{
			// LED soll eingeschaltet werden
			switch_rxled(civ,ON);
		}
		
		if(ledgn_state[civ] > 0)
		{
			ledgn_state[civ]--;
			if(ledgn_state[civ] == 0)
			{
				// LED soll ausgeschaltet werden
				switch_rxled(civ,OFF);
			}
		}
		
		// roteTX LEDs
		if(ledrd_state[civ] == LEDONTIME_RD)
		{
			// LED soll eingeschaltet werden
			switch_txled(civ,ON);
		}
		
		if(ledrd_state[civ] > 0)
		{
			ledrd_state[civ]--;
			if(ledrd_state[civ] == 0)
			{
				// LED soll ausgeschaltet werden
				switch_txled(civ,OFF);
			}
		}
	}
}

void rs232_leds()
{
	static uint8_t oldv10=0, oldv20=0;

	uint8_t v = PORTD.IN;
	uint8_t v10 = v & 0x10;
	uint8_t v20 = v & 0x20;
	
	if(v10 != oldv10 && v10 == 0)
	led_rx(RS232);

	if(v20 != oldv20 && v20 == 0)
	led_tx(RS232);
	
	oldv10 = v10;
	oldv20 = v20;
}

void einschaltblinken()
{
	uint8_t i;

	for(i=CIV1; i<=RS232; i++)
	{
		led_rx(i);
		_delay_ms(100);
	}
	for(i=0; i<8; i++)
	{
		led_tx(i);
		_delay_ms(100);
	}
}
