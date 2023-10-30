/******************************************************************************

30/10/23
Alessandro Di Rberto

Scrivere un programma che riceve in input due numeri interi e ne scambia il contenuto

*******************************************************************************/
#include <stdio.h>

int main()
{
   int a, b, c;
   
   printf("Inserisci i numeri \"A, B\": ");
   scanf("%d, %d", &a, &b);
   
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
