#include <main.h>

void (*txfunc[7])(char);

void init_tx()
{
	txfunc[0] = &putchar_usartc0;
	txfunc[1] = &putchar_usartc1;
	txfunc[2] = &putchar_usartd0;
	txfunc[3] = &putchar_usartd1;
	txfunc[4] = &putchar_usarte0;
	txfunc[5] = &putchar_usarte1;
	txfunc[6] = &putchar_usartf0;
}

void civ_tx(uint8_t data, uint8_t serIF)
{
	txfunc[serIF](data);
	led_tx(serIF);
}

void send_fifo()
{
	uint8_t framelen;
	uint8_t data[FRAMELEN+4];
	uint8_t civ, i;
	uint8_t chantab[7] = {0,0,0,0,0,0,0};   // auf 1 setzen, wenn an diesen CIV Kanal gesendet werden soll

	framelen = GetFrameFromFifo(data+3);
	
	if(framelen != 0)
	{
		// Routing:
		// sende Daten nur zu einem CIV Interface wenn dessen civ_adr =0 ist
		// oder die Dest-Adresse genau übereinstimmt
		for(civ=CIV1; civ<=CIV7; civ++)
		{
			if  (data[3] == 0 || civ_adr[civ] == data[3])
			{
				chantab[civ] = 1;
			}
		}
		
		data[0] = ROUTERID; // Kennung dass dieser Frame vom Router kommt
		data[1] = 0xfe;
		data[2] = 0xfe;
		data[framelen+3] = 0xfd;
		// Daten aus dem Fifo gelesen
		// sende zu allen CIV Interfaces
		for(i=0; i<(framelen+4); i++)
		{
			for(civ=CIV1; civ<=CIV7; civ++)
			{
				if(chantab[civ])
				civ_tx(data[i],civ);
			}
		}
	}
}
