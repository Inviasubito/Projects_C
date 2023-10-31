#define _CRT_SECURE_NO_WARNINGS
/******************************************************************************

31/10/23
Alessandro Di Roberto

Su una scacchiera 8x8 sono posizionati due pezzi: il Re bianco e la Regina nera.
Si scriva un programma che, acquisite le posizioni del Re e della Regina, determini se la Regina è in
posizione tale da poter mangiare il Re.
Le posizioni dei due pezzi sono identificate mediante la riga e la colonna su cui si trovano, espresse
come numeri interi tra 1 e 8.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int x_k, y_k;
    int x_q, y_q;

    printf("Inserisci la posizione della Re [\"X, Y\"]:");
    scanf("%d, %d", &x_k, &y_k);

    printf("Inserisci la posizione della Regina [\"X, Y\"]:");
    scanf("%d, %d", &x_q, &y_q);

    //H/V
    if (x_k == x_q ||
        y_k == y_q)
        printf("Scacco matto!");
    else
    {
        int done = 0;
        int c = 0;

        //Usa il coefficiente angolare!!
        for (int i = -8; i <= 8 && done == 0; i++)
        {
            if ((x_q + i == x_k && y_q + i == y_k) ||
                (x_q + i == x_k && y_q - i == y_k))
                done = 1;
        }

        if (done)
            printf("Scacco matto!");
        else
            printf("Ancora in gioco.");
    }

    return 0;
}

//Soluzione Salvatore Pappagallo
int main() 
{
    float kingR, kingC, queenR, queenC, true = 0;

    printf("Inserisci la riga del Re : ");
    scanf("%f", &kingR);
    printf("Inserisci la colonna del Re : ");
    scanf("%f", &kingC);
    printf("Inserisci la riga della Regina : ");
    scanf("%f", &queenR);
    printf("Inserisci la riga della Regina : ");
    scanf("%f", &queenC);

    while (true == 0)
    {
        if (kingR == queenR) 
        {
            printf("La Regina ha mangiato il Re!\n");
            true = 1;
        }

        if (kingC == queenC) 
        {
            printf("La Regina ha mangiato il Re!\n");
            true = 1;
        }

        if (abs(kingR - queenR) / abs(kingC - queenC) == 1.0) 
        {
            printf("La Regina ha mangiato il Re!\n");
            true = 1;
        }
    }
    return 0;
}