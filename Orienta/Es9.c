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
    int sum = 1;

    printf("Numero: ");
    scanf("%d", &v);

    for (int i = 0; i < 3; i++)
        sum *= v;

    printf("Il cubo di %d è %d", v, sum);

    return 0;
}