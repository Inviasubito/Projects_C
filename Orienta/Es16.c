#define _CRT_SECURE_NO_WARNINGS
/******************************************************************************

31/10/23
Alessandro Di Roberto

Scrivere un programma che chieda quanti valori verranno introdotti dalla tastiera, li chieda tutti e successivamente
li visualizzi dall'ultimo al primo
Scrivere un programma che chieda quanti valori verranno introdotti dalla tastiera, li chieda tutti e successivamente
visualizzi prima tutti i valori pari nell'ordine in cui sono stati inseriti e poi tutti i valori dispari nell'ordine inverso
Esempio:
dati i valori: 8 1 3 2 8 6 5, il programma visualizza: 8 2 8 6 5 3 1
Si ipotizzi di avere 2 vettori A e B di dimensione fissata opportunamente inizializzati con valori casuali
Valorizzare gli elementi di un terzo vettore secondo questa logica:
- nel 1° elemento la somma del 1° elemento di A e del 1° elemento di B,
- nel 2° elemento la somma del 2° elemento di A e del 2° elemento di B e cosi via
Visualizzare poi tutti gli elementi di posizione pari di C (il 2°, il 4°, ... ) e poi tutti quelli di posizione dispari (1°, 3°, ... )
Esempio:
- vettori di lunghezza 4,
- in A sono stati messi i valori: 3 5 2 6 e in B: 3 2 6 3
- verranno quindi calcolati e messi in C i valori: 6 7 8 9
- e quindi stampati i valori: 7 9 6 8.

*******************************************************************************/

#include <stdio.h>

int main1();
void InitRndVector(int[], int);
void printArr(const int[], int);

int main2();
void printOdd(const int[], int);
void printReverseEven(const int[], int);

int main3();
void printReverse(const int[], int);

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

#define LENGTH 5

int main1()
{
    int a[LENGTH];
    int b[LENGTH];
    int c[LENGTH];

    InitRndVector(a, LENGTH);
    InitRndVector(b, LENGTH);

    for (int i = 0; i < LENGTH; i++)
        c[i] = a[i] + b[i];

    printArr(a, LENGTH);
    printArr(b, LENGTH);
    printArr(c, LENGTH);

    return 0;
}

void InitRndVector(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        arr[i] = rand();
}

void printArr(const int arr[], int len)
{
    printf("Stampa array: [ ");

    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf(" ]\n");
}

int main2()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int len = sizeof(arr) / sizeof(arr[0]);

    printOdd(arr, len);
    printReverseEven(arr, len);

    return 0;
}

void printOdd(const int arr[], int len)
{
    printf("Valori pari: \n");

    for (int i = 0; i < len; i++)
    {
        if (arr[i] % 2 == 0)
            printf("%d ", arr[i]);
    }

    printf("\n");
}

void printReverseEven(const int arr[], int len)
{
    printf("Valori dispari in ordine inverso: \n");

    for (int i = len - 1; i >= 0; i--)
    {
        if (arr[i] % 2 != 0)
            printf("%d ", arr[i]);
    }

    printf("\n");
}


int main3()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int len = sizeof(arr) / sizeof(arr[0]);

    printReverse(arr, len);

    return 0;
}

void printReverse(const int arr[], int len)
{
    printf("Array: [ ");

    for (int i = len - 1; i >= 0; i--)
        printf("%d ", arr[i]);

    printf(" ]");
}