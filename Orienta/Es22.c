#define _CRT_SECURE_NO_WARNINGS
/******************************************************************************

7/11/23
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
	FILE* f;
	char* fileName = "tmp.txt";

	//r -> lettura
	//w -> scrittura (se esiste, lo elimina)
	//a -> append, scrittura (aggiunge il nuovo contenuto al file)
	f = fopen(fileName, "r");

	if (f)
	{
		fclose(f);
	}
	else
		fprintf(stderr, "Err.\n");

	printf("Possibile numero di file contemporaneamente aperti: %d", FOPEN_MAX);
}

void es2()
{

}