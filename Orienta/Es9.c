/******************************************************************************

30/10/23
Alessandro Di Roberto

Si scriva un programma che letto un numero intero positivo dallo standard input, visualizzi a terminale il
cubo del numero stesso facendo uso soltanto di operazioni di somma.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int v;
    int sum = 0;

    printf("Numero: ");
    scanf("%d", &v);

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            for (int k = 0; k < v; k++)
                sum += 1;

    printf("Il cubo di %d è %d", v, sum);

    return 0;
}