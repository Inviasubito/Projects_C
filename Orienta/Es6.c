/******************************************************************************

30/10/23
Alessandro Di ROberto

Scrivere un programma che riceve in input due numeri interi e ne scambia il contenuto

*******************************************************************************/
#include <stdio.h>

int main()
{
    int a, b, c;

    printf("A:");
    scanf("%d", &a);
    printf("B:");
    scanf("%d", &b);

    printf("Prima dello scambio:\n");
    printf("A: %d \n", a);
    printf("B: %d \n", b);

    c = a;
    a = b;
    b = c;

    printf("Dopo lo scambio:\n");
    printf("A: %d \n", a);
    printf("B: %d \n", b);

    return 0;
}