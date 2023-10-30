/******************************************************************************

30/10/23
Alessandro Di Roberto

Scrivere un programma che, letti tre numeri interi a, b, c dallo standard input, stampi a terminale la sequenza dei tre
numeri in ordine monotono non decrescente
Esempio : a = 10, b = 7, c = 9 deve dare in uscita 7 9 10

*******************************************************************************/

#include <stdio.h>
#define length 3

int main()
{
    int v[length];

    printf("Add %d items: ", length);
    scanf("%d %d %d", &v[0], &v[1], &v[2]);

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 1; j < length; j++)
        {
            if (v[i] > v[j])
            {
                int t = v[i];
                v[i] = v[j];
                v[j] = t;
            }
        }
    }

    printf("Items: [");
    for (int i = 0; i < 3; i++)
        printf("%d ", v[i]);

    printf("]");

    return 0;
}