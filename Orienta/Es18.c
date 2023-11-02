#define _CRT_SECURE_NO_WARNINGS
/******************************************************************************

2/11/23
Alessandro Di Roberto

Data una matrice di R righe e C colonne
scrivere un programma che chieda all'utente le dimensioni r e c di una matrice tali che r s R e c s C e poi visualizzi tutte le
sottomatrici di dimensioni rxc della matrice data la cui somma degli elementi è uguale a zero

*******************************************************************************/

#include <stdio.h>
#define M_R 4
#define M_C 5

int sumSub(int m[M_R][M_C], int start_r, int start_c, int s_c, int s_r);

int main()
{
    int m[M_R][M_C] =
    {
        {-2, -2, 4, 9, 7},
        {-9, 13, -5, 22, 8},
        {16, -9, 1, -9, 2},
        {3, 2, 33, 2, 9}
    };

    int p_r, p_c, p_v;

    printf("Inserisci la dimensione della sottomatrice [rxc:valore]:");
    scanf("%dx%d:%d", &p_r, &p_c, &p_v);

    int start_r = 0;
    int start_c = 0;

    while (start_r + p_r <= M_R && start_c + p_c <= M_C)
    {
        int v = sumSub(m, start_r, start_c, p_r, p_c);
        if (v == p_v)
        {
            for (int i = start_r; i < start_r + p_r; i++)
            {
                for (int j = start_c; j < start_c + p_c; j++)
                    printf("%d\t", m[i][j]);
                printf("\n");
            }

            printf("\n");
        }
        /*else
        {
            printf("NO***\n");
            for (int i = start_r; i < start_r + p_r; i++)
            {
                for (int j = start_c; j < start_c + p_c; j++)
                    printf("%d\t", m[i][j]);
                printf("\n");
            }

            printf("\n");
        }*/

        if (start_r + p_r < M_R)
            start_r++;
        else
        {
            start_r = 0;
            start_c++;
        }
    }

    return 0;
}

int sumSub(int m[M_R][M_C], int start_r, int start_c, int s_c, int s_r)
{
    int v = 0;
    for (int i = start_r; i < start_r + s_r; i++)
    {
        for (int j = start_c; j < start_c + s_c; j++)
            v += m[i][j];
    }

    return v;
}

void print(const int m[M_R][M_C])
{
    printf("Stampa:\n");

    for (int i = 0; i < M_R; i++)
    {
        for (int j = 0; j < M_C; j++)
            printf("%d\t", m[i][j]);
        printf("\n");
    }

    printf("\n");
}