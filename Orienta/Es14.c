/******************************************************************************

31/10/23
Alessandro Di Roberto

Scrivere un programma che legge da stdin una sequenza (di lunghezza arbitraria) di numeri interi
positivi, terminata da 0, e indica, alla fine della sequenza, qual è la lunghezza della massima
sottosequenza di numeri consecutivi in ordine crescente.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int g_max = 0;
    int maxL = 1;
    int c;
    int old = -1;

    printf("Inserisci la sequenza numerica: ");

    do
    {
        scanf(" %d", &c);

        if (old == -1)
            old = c;

        if (old <= c)
            maxL++;
        else
        {
            if (maxL > g_max)
                g_max = maxL;

            maxL = 1;
        }

        old = c;

    } while (c != 0);

    printf("La sequenza massima è stata di %d valori numerici.", g_max);

    return 0;
}