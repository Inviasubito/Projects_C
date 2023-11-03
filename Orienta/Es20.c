#define _CRT_SECURE_NO_WARNINGS
/******************************************************************************

3/11/23
Alessandro Di Roberto

Scrivere un programma che date due stringhe in input stampi la più lunga
La prima se sono di uguale lunghezza
Scrivere un programma che date due stringhe in input stampi la maggiore
Scrivere un programma che chieda in input una stringa e calcoli da quanti caratteri è composta
Non usare la funzione strlen !!
Scrivere un programma che data una stringa in input, la converta tutta in maiuscolo
Scrivere un programma che data una stringa in input verifichi se essa contiene almeno una 'A' tra i primi 10 caratteri
Scrivere un programma che richieda in input una stringa e conti quante cifre essa contiene
Esempio "Ciao2004! C6?" deve dare 5
Scrivere un programma che richieda in input una stringa e conti di quante lettere maiuscole, lettere minuscole, cifre
e altri caratteri è composta
Esempio "Ciao2004! C6?" deve dare: maiuscole:2, minuscole: 3, cifre: 5, altri: 3
Scrivere un programma che date in input due stringhe di lunghezza diversa indichi se la più corta è contenuta solo
una volta nella più lunga
Scrivere un programma che verifichi se la stringa data è composta di due parti uguali, trascurando il carattere
centrale se la lunghezza è dispari (es. "CiaoCiao", "CiaoXCiao")
Scrivere un programma che chieda all'utente di inserire una frase (max 128 caratteri), conti quante sono le parole
(sequenze di lettere dell'alfabeto) che la compongono e la lunghezza media delle parole stesse
Esempio
Se viene dato in input: "leri sono andato a mangiare all'una!"
il programma deve indicare che ci sono 7 parole e che la lunghezza media è 4.14 caratteri
Senza usare l'apposita funzione di libreria, scrivere un programma che converta una stringa in un numero
Il programma deve segnalare errore qualora la stringa non rappresenti un numero
Ad esempio:
12409
00234
54,65
3y,441
12409
234
54.65
errore
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void es1();
void es2();
void es3();
void es4();
void es5();
void es6();
void es7();
void es8();
void es9();
void es10();
void es11();

int main()
{
	es9();
	int v;

	printf("Seleziona l'esercizio: ");

	scanf("%d", &v);

	switch (v)
	{
	case 1:
		es1();
		break;
	case 2:
		es2();
		break;
	case 3:
		es3();
		break;
	case 4:
		es4();
		break;
	case 5:
		es5();
		break;
	case 6:
		es6();
		break;
	case 7:
		es7();
		break;
	default:
		printf("Selezione non valida.\n");
		break;
	}

	return 0;
}

//1

#define MAX_STRING_LENGTH 20

void es1()
{
	char str1[MAX_STRING_LENGTH];
	char str2[MAX_STRING_LENGTH];
	int str1_l = 0;
	int str2_l = 0;

	printf("Scrivi due stringhe [\"stringa1\" - \"stringa2\"]: \n");
	scanf("%s - %s", str1, str2);

	str1_l = strlen(str1);
	str2_l = strlen(str2);

	if (str2_l > str1_l)
		printf("La stringa più lunga è la seconda (\"%s\")", str2);
	else
		printf("La stringa più lunga è la prima (\"%s\")", str1);
}

//2

void es2()
{
	char str1[MAX_STRING_LENGTH];
	char str2[MAX_STRING_LENGTH];
	int v = 0;
	int str2_l = 0;

	printf("Scrivi due stringhe [\"stringa1\" - \"stringa2\"]: \n");
	scanf("%s - %s", str1, str2);

	v = strcmp(str1, str2);

	if (v < 0)
		printf("La stringa più lunga è la seconda (\"%s\")", str2);
	else if (v > 0)
		printf("La stringa più lunga è la prima (\"%s\")", str1);
	else
		printf("Le stringhe sono uguali.");
}

//3

void es3()
{
	char str1[MAX_STRING_LENGTH];
	int str1_l = 0;
	int v = 0;

	printf("Scrivi una stringa [\"stringa1\"]: \n");
	scanf("%s", str1);

	for (int i = 0; i < MAX_STRING_LENGTH && !v; i++)
	{
		if (str1[i] != '\0')
			str1_l++;
		else
			v = 1;
	}

	printf("La stringa \"%s\" è composta da %d caratteri.", str1, str1_l);
}

//4

void es4()
{
	char str1[MAX_STRING_LENGTH];
	char str1_upper[MAX_STRING_LENGTH];
	int str1_l = 0;
	int v = 0;

	printf("Scrivi una stringa [\"stringa1\"]: \n");
	scanf("%s", str1);

	for (int i = 0; i < MAX_STRING_LENGTH && !v; i++)
	{
		if (str1[i] != '\0')
			str1_upper[i] = toupper(str1[i]);
		else
		{
			str1_upper[i] = '\0';
			v = 1;
		}
	}

	printf("La tua nuova stringa: %s", str1_upper);
}

// 5

void es5()
{
	char str1[MAX_STRING_LENGTH];
	int str1_lenCheck = 10;
	int v = 0;
	int ck = -1;

	printf("Scrivi una stringa [\"stringa1\"]: \n");
	scanf("%s", str1);

	for (int i = 0; i < str1_lenCheck && !v; i++)
	{
		if (str1[i] != '\0' && str1[i] == 'A')
		{
			ck = i;
			v = 1;
		}
	}

	if (ck >= 0)
		printf("La stringa che hai inserito contiene la lettera \"A\" nella posizione %d", ck);
	else
		printf("La stringa non contine la lettera \"A\"");
}

// 6

void es6()
{
	char str1[MAX_STRING_LENGTH];
	int v = 0;
	int ck = 0;

	printf("Scrivi una stringa [\"stringa1\"]: \n");
	fgets(str1, sizeof(str1), stdin);

	for (int i = 0; i < MAX_STRING_LENGTH && !v; i++)
	{
		if (str1[i] != '\0' && isdigit(str1[i]))
			ck++;
		else if (str1[i] == '\0')
			v = 1;
	}

	if (ck >= 0)
		printf("La stringa che hai inserito contiene %d valori numerici.", ck);
	else
		printf("La stringa non contine valori numerici.");
}

// 7

void es7()
{
	char str1[MAX_STRING_LENGTH];
	int v = 0;

	int lowers = 0;
	int uppers = 0;
	int numbers = 0;
	int chars = 0;

	printf("Scrivi una stringa [\"stringa1\"]:");
	fgets(str1, sizeof(str1), stdin);

	for (int i = 0; i < MAX_STRING_LENGTH && !v; i++)
	{
		if (str1[i] != '\0')
		{
			if (isdigit(str1[i]))
				numbers++;
			else if (islower(str1[i]))
				lowers++;
			else if (isupper(str1[i]))
				lowers++;
			else
				chars++;
		}
		else
			v = 1;
	}

	printf("La stringa che hai inserito contiene %d valori numerici, %d valori minuscoli, %d valori maiuscoli e altri %d caratteri.", numbers, lowers, uppers, chars);
}

// 8

void es8()
{
	//si poteva usare strstr!

	char str_max[MAX_STRING_LENGTH];
	char str_min[MAX_STRING_LENGTH];

	int max_l = 0;
	int min_l = 0;
	int founded = 0;

	printf("Scrivi due stringhe [\"stringa1\"]: \n");
	fgets(str_max, sizeof(str_max), stdin);
	printf("Scrivi due stringhe [\"stringa2\"]: \n");
	fgets(str_min, sizeof(str_min), stdin);

	max_l = strlen(str_max);
	min_l = strlen(str_min);

	if (max_l < min_l)
	{
		char tmp[MAX_STRING_LENGTH];

		strncpy(tmp, str_max, sizeof(str_max));
		strncpy(str_max, str_min, sizeof(str_min));
		strncpy(str_min, tmp, sizeof(tmp));

		int v = max_l;
		max_l = min_l;
		min_l = v;
	}

	if (min_l != max_l)
	{
		for (int i = 0; i < max_l; i++)
		{
			if (str_max[i] == str_min[0] && i + min_l <= max_l)
			{
				int eq = 1;
				for (int j = 0; j < min_l; j++)
				{
					if (str_max[i + j] != str_min[j])
						eq = 0;
				}

				if (eq)
				{
					founded++;
					eq = 0;
				}
			}
		}

		if (founded > 0)
			printf("Sono state trovate %d occorrenze nella stringa: ", founded);
		else
			printf("Non sono state trovate occorrenze nella stringa");
	}
	else
		printf("Le stringhe hanno stessa lunghezza");
}

// 9

void es9()
{
	char str_max[MAX_STRING_LENGTH];
	char str_min[MAX_STRING_LENGTH];

	int max_l = 0;
	int min_l = 0;
	int founded = 0;

	printf("Scrivi due stringhe [\"stringa1\"]: \n");
	fgets(str_max, sizeof(str_max), stdin);
	printf("Scrivi due stringhe [\"stringa2\"]: \n");
	fgets(str_min, sizeof(str_min), stdin);

	max_l = strlen(str_max) - 1;
	min_l = strlen(str_min) - 1;

	if (max_l < min_l)
	{
		char tmp[MAX_STRING_LENGTH];

		strncpy(tmp, str_max, sizeof(str_max));
		strncpy(str_max, str_min, sizeof(str_min));
		strncpy(str_min, tmp, sizeof(tmp));

		int v = max_l;
		max_l = min_l;
		min_l = v;
	}

	int pp = max_l % min_l != 0;

	for (int i = 0; i < max_l; i++)
	{
		if (pp && i != max_l / 2)	//se dispari ignoro il carattere l/2
		{
			if (str_max[i] == str_min[0] && i + min_l <= max_l)
			{
				int eq = 1;
				for (int j = 0; j < min_l; j++)
				{
					if (str_max[i + j] != str_min[j])
						eq = 0;
				}

				if (eq)
				{
					founded++;
					eq = 0;
				}
			}
		}
	}


	if (founded == 2)
		printf("Sono state trovate le %d occorrenze nella stringa: ", founded);
	else
		printf("Non sono state trovate le occorrenze indicate nella stringa");
}

// 10

#define MAX_LENGTH 128

void es10()
{
	char str[MAX_LENGTH] = "Ieri sono andato a mangiare all'Una";
	int w_count = 0;
	float avg = 0;
	int v = 0;

	/*
	printf("Inserisci la frase: ");
	fgets(str, sizeof(str), stdin);
	*/

	for (int i = 0; i < MAX_LENGTH && !v; i++)
	{
		if (str[i] == '\0')
			v = 1;
		else if (isblank(str[i]) || str[i] == '\'') //in questo modo si da per scontato che ci sia un solo blanck
			w_count++;
		else
			avg++;
	}

	printf("Ci sono %d parole con una media di %f l'una", w_count + 1, (float)(avg / w_count));
}

void es11()
{
	char str[MAX_STRING_LENGTH] = "02.345";
	float number = 0;

	float decimal = 0;
	float integer = 0;
	int h_decimal = 0;

	for (int i = 0; i < MAX_STRING_LENGTH && number >= 0; i++)
	{
		int chr = str[i] - 48;
		if (str[i + 1] != '\0')
		{
			if (h_decimal > 0 || str[i] == '.' || str[i] == ',')
			{
				h_decimal++;

				float c = (float)(str[i + 1] - 48);

				for (int j = 0; j < h_decimal; j++)
					c /= 10;

				decimal = c;
			}
			else if (chr < 0 || chr > 9)
			{
				number = -1;
			}
			else
			{
				number *= 10;

				float c = (float)(str[i] - 48);
				integer = c;
			}

			if (number >= 0)
			{
				number += integer + decimal;

				integer = 0;
				decimal = 0;
			}
		}
	}

	if (number >= 0)
		printf("Il numero è: %f\n", number);
	else
		printf("Errore");
}