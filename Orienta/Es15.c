/******************************************************************************

31/10/23
Alessandro Di Roberto

Scrivi un programma per copiare 2 matrici NxM

*******************************************************************************/

#include <stdio.h>

#define N 2
#define M 3

void copy(const int[N][M], int[N][M]);
void print(const int[N][M]);

int main()
{
    int m1[N][M] = { { 2, 3 }, {9, 6, 8} };
    int m2[N][M] = { {0} };

    printf("Matrice prima della copia: \n");
    print(m2);

    copy(m1, m2);

    printf("Matrice dopo la copia: \n");
    print(m2);

    return 0;
}

void copy(const int m1[N][M], int m2[N][M])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            m2[i][j] = m1[i][j];
    }
}

void print(const int m[N][M])
{
    printf("Stampa:\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%d\t", m[i][j]);
        printf("\n");
    }

    printf("\n");
}