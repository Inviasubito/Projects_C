/******************************************************************************

30/10/23
Alessandro Di Roberto

Scrivere un programma in grado di acquisire in ingresso dall'utente un valore intero num e una sequenza
di interi che termina con uno 0 (zero).
Il programma deve stampare a video il numero di valori pari nella sequenza che sono divisori di num.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int num;
    int v = 1;
    int count = 0;

    printf("Num: ");
    scanf("%d", &num);

    while (v != 0)
    {
        printf("V: ");
        scanf("%d", &v);

        if (v != 0)
        {
            if (num % v == 0)
                count++;
        }
    }

    printf("Numeri divisibili per %d: %d", num, count);

    return 0;
}