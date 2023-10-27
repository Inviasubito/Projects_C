/******************************************************************************

//27/10/23
Alessandro Di Roberto

Scrivere un programma che chiede all'utente di inserire una sequenza di interi terminata quando
l'utente immette il valore 0.
Il programma stampa «SI» se la sequenza contiene un valore positivo seguito da uno negativo,
altrimenti stampa il messaggio «NO».
A vostra scelta, la stampa del messaggio "NO" può interrompere o meno l'inserimento dei valori.
Risolvere questo esercizio senza usare array

*******************************************************************************/
#include <stdio.h>

int isValid(int, int);

int main()
{
    int v1 = 0;
    int v2 = 0;
    int last = 0;
    int index = 0;

    do
    {
        printf("Inserisci valore: ");
        scanf(" %d", &last);
        
        if(last != 0)
        {
            if(index % 2)
                v2 = last;
            else
                v1 = last;
        }
        
        printf("\n");
        
        //Se la sequenza è errata, allora termino il ciclo
        if(index++ > 0 && !isValid(v1, v2))
            last = 0;
        
    } while(last != 0);
    
    printf("Sequenza terminata con risultato: %s", isValid(v1, v2) ? "Si" : "No");
}

int isValid(int v1, int v2)
{
    return v1 > 0 && v2 < 0;
}
