#define _CRT_SECURE_NO_WARNINGS
/******************************************************************************

8/11/23
Alessandro Di Roberto



*******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int runSelected(int);
typedef void (*void_t)();

void es1();
void es2();

int main()
{
	char c[3];
	int v = -1;

	do
	{
		printf("Seleziona esercizio: ");
		if (fgets(c, sizeof(c), stdin) != NULL)
		{
			if (sscanf(c, "%d", &v) == 1)
				v = runSelected(v);
		}
	} while (v == -1);

	return 0;
}

int runSelected(int v_index)
{
	void_t v[] =
	{
		es1,
		es2
	};

	int v_length = sizeof(v) / sizeof(v[0]);
	int result = -1;

	if (v_index > 0 && v_index <= v_length)
	{
		printf("****\tEsercizio %d\t****\n\n", v_index);
		v[v_index - 1]();
		printf("\n\n****\tEsercizio %d terminato\t****\n", v_index);

		result = 1;
	}
	else
		printf("Selezione non valida.\n");

	return result;
}

void es1()
{
	/*
	Tipologie di Embedded
	-> PLC: Programmable Logic Controller.
			Semplici, poco costosi, per lavorare su sistemi di automazione.
			Non per vasta scala. Svologno una sola funzione specifica.
			Linguaggi di programmazione: FBD (grafico), LD (grafico), ST (testuale), IL (testuale)
	-> MCU: Microcontrollori (es. Arduino).
			Sistema hw completo in un unico chip.
	-> SoC: System on Chip
			In sostanza mini pc, contengono al loro interno schede grafiche, encoder/decoder, usb ecc

	*/
}

void es2()
{

}