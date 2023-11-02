#define _CRT_SECURE_NO_WARNINGS
/******************************************************************************

31/10/23
Alessandro Di Roberto

Scrivere un programma che determini il massimo, il minimo, la somma e la media degli elementi di un array
Scrivere un programma che identifichi la più lunga sequenza di numeri consecutivi uguali presenti all'interno di un
array
Se vengono identificate più sequenze della stessa lunghezza, si consideri solo la prima identificata
Il programma deve indicare il valore ripetuto e il numero di ripetizioni di quel valore.
Esempio:
- input: 19 3 15 15 7 9 9 9 9 12 3 3 3
- output: numero: 9, ripetizioni: 4

*******************************************************************************/

#include <stdio.h>
#define LENGTH 5

void InitRndVector(int[], int);

int main1();
void printMax(int[], int);
void printMin(const int[], int);
void printSUM(const int[], int);
void printAVG(const int[], int);

int main2();

int main3();

int main()
{
    int v;

    printf("Seleziona l'esercizio: ");
    scanf("%d", &v);

    switch (v)
    {
    case 1:
        main1();
        break;
    case 2:
        main2();
        break;
    case 3:
        main3();
        break;
    default:
        printf("Non riconosco la funzione.");
        break;
    }
}

int main1()
{
    int a[LENGTH];
    InitRndVector(a, LENGTH);

    printMax(a, LENGTH);
    printMin(a, LENGTH);
    printSUM(a, LENGTH);
    printAVG(a, LENGTH);

    return 0;
}

void InitRndVector(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        arr[i] = rand();
}

void printMax(int arr[], int len)
{
    int max = arr[0];

    for (int i = 0; i < len; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    printf("Stampa MAX: %d \n", max);
}

void printMin(int arr[], int len)
{
    int min = arr[0];

    for (int i = 0; i < len; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }

    printf("Stampa MIN: %d \n", min);
}

void printSUM(int arr[], int len)
{
    int sum = 0;

    for (int i = 0; i < len; i++)
        sum += arr[i];

    printf("Stampa SOMMA: %d \n", sum);
}

void printAVG(int arr[], int len)
{
    int sum = 0;

    for (int i = 0; i < len; i++)
        sum += arr[i];

    printf("Stampa AVG: %d \n", sum / len);
}

/**************/

#define LEN 13

int main2()
{
    int arr[LEN] = { 19, 3, 15, 15, 7, 9, 9, 9, 9, 12, 3, 3, 3 };
    int m[LEN][2] = { {0} };

    for (int i = 0; i < LEN; i++)   //arr
    {
        m[i][0] = arr[i];

        for (int j = 0; j < LEN; j++)   //matrice
        {
            if (m[j][0] == arr[i])
                m[j][1]++;
        }
    }

    int max_Index = 0;
    int MAX_V = 0;
    for (int i = 0; i < LEN; i++)
    {
        if (MAX_V < m[i][1])
        {
            max_Index = i;
            MAX_V = m[i][1];
        }
    }

    printf("Valore massimo: %d, con %d ripetizioni.", m[max_Index][0], MAX_V);

    return 0;
}

/**************/
#define M_L 5
void print(const int m[M_L][M_L]);

void IncrementTop(int m[M_L][M_L], int*, int, int, int*);
void IncrementRight(int m[M_L][M_L], int, int, int*, int*);
void IncrementBotton(int m[M_L][M_L], int, int, int*, int, int*);
void IncrementLeft(int m[M_L][M_L], int, int*, int, int, int*);

int main3()
{
    int m[M_L][M_L];
    int index = 1;
    int k = 0, l = 0;
    int last_k = M_L - 1, last_l = M_L - 1;

    while (k <= last_k && l <= last_l)
    {
        IncrementTop(m, &k, l, last_l, &index);
        IncrementRight(m, k, last_k, &last_l, &index);
        IncrementBotton(m, k, l, &last_k, last_l, &index);
        IncrementLeft(m, k, &l, last_k, last_l, &index);
    }

    print(m);
}

void IncrementTop(int m[M_L][M_L], int* k, int l, int last_l, int* index)
{
    for (int i = l; i <= last_l; i++)
        m[*k][i] = (*index)++;
    (*k)++;
}

void IncrementRight(int m[M_L][M_L], int k, int last_k, int* last_l, int* index)
{
    for (int i = k; i <= last_k; i++)
        m[i][*last_l] = (*index)++;
    (*last_l)--;
}

void IncrementBotton(int m[M_L][M_L], int k, int l, int* last_k, int last_l, int* index)
{
    if (k <= *last_k)
    {
        for (int i = last_l; i >= l; i--)
            m[*last_k][i] = (*index)++;
        (*last_k)--;
    }
}

void IncrementLeft(int m[M_L][M_L], int k, int* l, int last_k, int last_l, int* index)
{
    if (*l <= last_l)
    {
        for (int i = last_k; i >= k; i--)
            m[i][*l] = (*index)++;
        (*l)++;
    }
}

void print(const int m[M_L][M_L])
{
    printf("Stampa:\n");

    for (int i = 0; i < M_L; i++)
    {
        for (int j = 0; j < M_L; j++)
            printf("%d\t", m[i][j]);
        printf("\n");
    }

    printf("\n");
}