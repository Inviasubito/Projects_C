/************************
Alessandro Di Roberto
27/10/23

Scrivere un programma che legge da tastiera una sequenza di numeri interi chiedendo all'utente quanto dovrà essere lunga la sequenza.
Al termine dell'acquisizione della sequenza il programma dovrà stampare:
- "OK" se tutti i numeri inseriti sono positivi e pari
- "KO" in caso contrario

************************/

#include <stdio.h>

int main()
{
    int is_pp = 1;
    int s_length = 0;
    int v = 0;
    
    printf("Quanto dovrà essere lunga la sequenza?\n");
    scanf ("%d",&s_length);
    
    for(int i = 0; i < s_length; i++)
    {
        printf("Valore [%d]: \n", i + 1);
        scanf(" %d", &v);
        
        is_pp = is_pp && v >= 0 && v % 2 == 0;
    }
    
    if(is_pp)
        printf("OK");
    else
        printf("KO");
    

    return 0;
}
