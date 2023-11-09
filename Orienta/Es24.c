#define _CRT_SECURE_NO_WARNINGS
/******************************************************************************

8/11/23
Alessandro Di Roberto

Scrivere con un editor un file contenente dei numeri, uno per riga.
Sviluppare poi un programma che chieda all'utente il nome di questo file, lo apra e calcoli e stampi
a video quanti sono i valori letti, il valore massimo, il valore minimo, la somma e la media di tutti i
valori presenti nel file

Scrivere un programma che chieda all'utente il nome di un file di testo e conti quante righe e quanti
caratteri esso contiene (non si considerino i caratteri di ritorno a capo ed eventuale fine file)

Scrivere un programma che legga un file contenente coppie di numeri interi (x e y), una per riga e
scriva un secondo file che contenga le differenze x - y, una per riga.
Si supponga che il file di input non abbia errori

Si scriva un programma che analizzi un file di testo e calcoli quante sono le parole che iniziano con
ciascuna lettera dell'alfabeto (non si faccia distinzione fra maiuscole e minuscole)
Esempio di output:
Parole che iniziano con A: 45
Parole che iniziano con B:
Parole che iniziano con C:
Parole che iniziano con Z:

Un file di testo contiene, in ciascuna riga separati da spazi, 2 o 3 valori reali:
1. nel primo caso si tratta della base e dell'altezza di un triangolo
2. nel secondo caso si tratta della base minore, della base maggiore e dall'altezza di un trapezio
Si scriva un programma che analizzi il file ed indichi qual è la riga del file corrispondente alla figura
geometrica di area maggiore e il valore di quest'area
Se si trovano figure di aree uguali, si consideri la prima di queste

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int runSelected(int);
typedef void (*void_t)();

void es1();
void es2();
void es3();
void es4();

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
		es2,
		es3,
		es4
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
	char ch;

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

/*
1
4
9
0
*/
void es2()
{
	char* path = "es1.txt";
	char c;
	char str[20];
	int count = 0;
	int max = 0;
	int min = -1;
	int sum = 0;

	FILE* f = fopen(path, "r");

	if (f != NULL)
	{
		while ((c = fgets(str, 5, f)) != NULL)
		{
			int v = atoi(str);
			count++;

			if (max < v)
				max = v;

			if (min == -1 || min > v)
				min = v;

			sum += v;
		}

		printf("Elementi: %d\n", count);
		printf("Massimo: %d\n", max);
		printf("Minimo: %d\n", min);
		printf("Somma: %d\n", sum);
		printf("Media: %f", (float)sum / (float)count);

		fclose(f);
	}
	else
	{
		fprintf(stderr, "Err.\n");
		perror("Error: ");
	}
}

/*
Ciao come va
Hello W
*/
void es3()
{
	char* path = "es3.txt";
	int arr['z' - 'a'] = { 0 };
	int sizeArr = sizeof(arr) / sizeof(arr[0]);
	char str[100];

	FILE* f = fopen(path, "r");

	if (f != NULL)
	{
		while ((fgets(str, 50, f)) != NULL)
		{
			for (int i = 0; i < strlen(str) - 1; i++)
			{
				int index = (int)(tolower(str[i]) - 'a');
				arr[index]++;
			}

			printf("Nella frase \"%s\" sono presenti: \n", str);
			for (int i = 0; i < sizeArr; i++)
			{
				if (arr[i] > 0)
				{
					printf("Parole con la lettera %c: %d\n", (char)(i + 'A'), arr[i]);
					arr[i] = 0;
				}
			}
			printf("\n");
		}

		fclose(f);
	}
	else
	{
		fprintf(stderr, "Err.\n");
		perror("Error: ");
	}
}

/*
20 30
2 30 20
*/
void es4()
{
	char* path = "es3.txt";
	int v;
	char c;
	int arr[3] = { 0 };

	FILE* f = fopen(path, "r");

	if (f != NULL)
	{
		int count = 0;
		while ((fscanf(f, "%d", &v)) == 1)
		{
			arr[count]++;
			c = fgetc(f);
			if (c == '\n')
				count++;
		}

		for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
		{
			if (arr[i] == 2)
				printf("Riga %d corrisponde al triangolo: \n", i + 1);
			else if (arr[i] == 3)
				printf("Riga %d corrisponde al trapezio\n", i + 1);
		}

		fclose(f);
	}
	else
	{
		fprintf(stderr, "Err.\n");
		perror("Error: ");
	}
}