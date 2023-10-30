/******************************************************************************

30/10/23
Alessandro Di Roberto

Si scriva un programma che letto un numero intero positivo dallo standard input, visualizzi a terminale il
quadrato del numero stesso facendo uso soltanto di operazioni di somma.
Si osservi che il quadrato di ogni numero intero positivo N può essere costruito sommando tra loro i primi
N numeri dispari.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int v;
    int sum = 0;

    printf("Numero: ");
    scanf("%d", &v);

    for (int i = 1; i <= v * 2; i += 2)
        sum += i;

    printf("Il quadrato di %d è %d", v, sum);

    return 0;
}