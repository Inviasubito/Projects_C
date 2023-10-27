/******************************************************************************

27/10/23
Alessandro Di Roberto

Scrivere un programma che chiede all'utente di inserire una sequenza di interi.
Il programma continua a chiedere all'utente di inserire valori fintanto che i valori inseriti soddisfano
almeno una delle seguenti condizioni:
- il valore inserito è negativo e divisibile per 2
- il valore inserito è positivo e divisibile per 3
Al termine il programma stampa la somma di tutti i valori inseriti escluso quello ha violato le condizioni.
Risolvere questo esercizio senza usare array.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int sum = 0;
    int v = 0;
    int verified = 1;
    
    while(verified)
    {
        printf("Inserisci un valore: ");
        scanf("%d", &v);
        
        if((v < 0 && v % 2 == 0) || (v > 0 && v % 3 == 0))
            sum += v;
        else 
            verified = 0;
    }
    
    printf("Somma: %d", sum);

    return 0;
}
