#include <main.h>

uint8_t rx_state[7] = {0,0,0,0,0,0,0};    // state 0=warten, 1=lesen
uint8_t rx_last[7] = {0,0,0,0,0,0,0};     // zuletzt empfangenes Zeichen um 2x FE zu erkennen
uint8_t rx_router[7] = {0,0,0,0,0,0,0};   // =1 wenn 37,FE empfangen wurde und der Frame daher vom Router stammen könnte
uint8_t act_civ = CIV1;					  // aktuell bearbeitetes CIV Interface (immer der Reihe nach)
// RX Puffer pro Kanal
uint8_t rxbuf[7][RXBUFLEN];
uint8_t rxidx[7] = {0,0,0,0,0,0,0};

// Routingtabelle
// für jeden der 7 CIV Kanäle wird hier die CIV Adresse gespeichert
uint8_t civ_adr[7] = {0,0,0,0,0,0,0};
uint8_t lifetime[7] = {0,0,0,0,0,0,0};  // lifetime der chantab in Sekunden

// Aufruf 2x pro Sekunde aus dem Timer IRQ
void handle_routing_lifetime()
{
	uint8_t civ;

	for(civ = CIV1; civ <= CIV7; civ++)
	{
		if(lifetime[civ] > 0)
		{
			lifetime[civ]--;
			if(lifetime[civ] == 0)
			civ_adr[civ] = 0;   // CIV Adresse zu alt, löschen
		}
	}
}

// lese CIV Frames von allen Interfaces CIV 1 bis 7 und schreibe sie in einen Fifo
void read_civ()
{
	int (*rxfunc)();
	int v;

	switch(act_civ)
	{
		case CIV1: rxfunc = &getchar_usartc0; break;
		case CIV2: rxfunc = &getchar_usartc1; break;
		case CIV3: rxfunc = &getchar_usartd0; break;
		case CIV4: rxfunc = &getchar_usartd1; break;
		case CIV5: rxfunc = &getchar_usarte0; break;
		case CIV6: rxfunc = &getchar_usarte1; break;
		case CIV7: rxfunc = &getchar_usartf0; break;
		default: rxfunc = &getchar_usartf0; //nur damit der Compiler nicht meckert
	}
	
	v = rxfunc();
	if(v != -1)
	{
		// ein Byte wurde empfangen
		if(v == 0xfe && rx_last[act_civ] == 0xfe && rx_router[act_civ] == 0)
		{
			// ein Start wurde erkannt, und es kam nicht vom Router selbst
			// beginne einen neuen Frame, egal ob der alte fertig war oder nicht
			rxidx[act_civ] = 0;
			rx_state[act_civ] = 1;
		}
		else
		{
			if(rx_state[act_civ] == 1)
			{
				// es läuft ein Empfang
				if(v == 0xfd)
				{
					// der aktuelle Frame ist fertig
					// schreibe ihn in den Fifo
					led_rx(act_civ);
					civ_adr[act_civ] = rxbuf[act_civ][1];           // merke die Source-Adresse fürs Routing
					lifetime[act_civ] = LIFETIME;
					FrameIntoFifo(rxbuf[act_civ],rxidx[act_civ]);
					// und starte neu
					rx_state[act_civ] = 0;
					rxidx[act_civ] = 0;
				}
				else
				{
					// mitten im Frame-Empfang
					rxbuf[act_civ][rxidx[act_civ]] = v;
					rxidx[act_civ]++;
					if(rxidx[act_civ] == RXBUFLEN)
					{
						// Überlauf, verwerfe den aktuellen Frame
						rx_state[act_civ] = 0;
						rxidx[act_civ] = 0;
					}
				}
			}
		}
		
		// prüfe ob es Daten vom Router sind, wenn ja, dann ignorieren
		if(rx_last[act_civ] == ROUTERID && v == 0xFE)
		rx_router[act_civ] = 1;
		else
		rx_router[act_civ] = 0;
		
		rx_last[act_civ] = v;
	}
	
	if(++act_civ > CIV7)
	act_civ = CIV1;
}
