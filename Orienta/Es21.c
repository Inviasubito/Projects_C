#define _CRT_SECURE_NO_WARNINGS
/******************************************************************************

3/11/23
Alessandro Di Roberto

Si scriva un programma che chieda all'utente le coordinate x e y di 4 punti nel piano, li memorizzi in un vettore di
struct, quindi calcoli la lunghezza del perimetro del quadrilatero e la distanza minima tra i punti
Si scriva un programma che dichiari il seguente tipo di dati che descrive un generico poligono regolare
struct poligono {
int nlati;
double lato;
Si scrivano le seguenti funzioni e le si chiamino da un main di prova:
- struct poligono creapoli(void);
chiede all'utente il numero lati e la lunghezza lato, quindi restituisce una struct poligono
- double areapoli(struct poligono p);
calcola l'area del poligono ricevuto in ingresso
- double perimpoli(struct poligono p);
calcola il perimetro del poligono passato

*******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void es1();
void es2();

int main()
{
	char c[5];
	int v = -1;

	printf("Seleziona esercizio: ");
	while (v == -1 && fgets(c, sizeof(c), stdin) != NULL)
	{
		if (sscanf(c, "%d", &v) == 1)
			printf("***\tEsercizio %d\t****\n", v);
	}

	switch (v)
	{
	case 1:
		es1();
		break;
	case 2:
		es2();
		break;
	default:
		printf("Selezione non valida.\n");
		break;
	}

	return 0;
}

#define ES1_ARR_POINT 4
float p_distance(struct point_t p1, struct point_t p2);

struct point_t
{
	float x;
	float y;
};

void es1()
{
	struct  point_t pt[ES1_ARR_POINT] =
	{
		{0, 0},
		{3, 0},
		{3, 3},
		{0, 3}
	};

	float p = 0;
	float d_min = 0;

	/*printf("Inserisci le 4 coordinate:\n");
	for (int i = 0; i < ES1_ARR_POINT; i++)
	{
		printf("Coordinata (X%d, Y%d): ", i, i);
		scanf("%d, %d", &(pt[i]).x, &(pt[i]).y);
	}*/

	for (int i = 0; i < ES1_ARR_POINT; i++)
	{
		float d = p_distance(pt[0], pt[i]);

		if (i != 0 || (d > 0 && d < d_min))
			d_min = d;
	}

	for (int i = 0; i < ES1_ARR_POINT; i++)
	{
		p += p_distance(pt[ES1_ARR_POINT - 1 - i], pt[i]);
	}

	printf("Perimetro: %f \n", p);
	printf("Distanza minima: %f \n", d_min);

}

float p_distance(struct point_t p1, struct point_t p2)
{
	return sqrtf(powf(p2.x - p1.x, 2) + powf(p2.y - p1.y, 2));
}

// es2

struct poligono_t
{
	int nlati;
	double lato;
};

struct poligono_t creapoli(void);
double areapoli(struct poligono_t);
double perimpoli(struct poligono_t);
double apotema(struct poligono_t);

void es2()
{
	struct poligono_t p = creapoli();

	printf("Area del poligono: %f \n", areapoli(p));
	printf("Perimetro del poligono: %f \n", perimpoli(p));
}

struct poligono_t creapoli()
{
	struct poligono_t p;
	int nlati;
	double lato;

	printf("Inserisci il numero di lati e la lunghezza lato [num_lati, lung_lato]:");
	scanf("%d, %lf", &nlati, &lato);

	p.lato = lato;
	p.nlati = nlati;

	return p;
}

double areapoli(struct poligono_t p)
{
	return 0.5f * perimpoli(p) * apotema(p);
}

double perimpoli(struct poligono_t p)
{
	return p.lato * p.nlati;
}

double apotema(struct poligono_t p)
{
	double degree = 180.0 / p.nlati;
	double radian = degree * (3.14f / 180.0f);
	double ta = tan(radian);

	return p.lato / (2 * ta);
}