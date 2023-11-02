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

#define P_R 3
#define P_C 3

int compareSubMatrix(int m[M_R][M_C], int p[P_R][P_C], int s_r, int s_c, struct Point* pt, int* indexArr);

struct Point
{
    int x;
    int y;
};

int main()
{
    int m[M_R][M_C] =
    {
        {2, 12, 4, 9, 7},
        {21, 25, 9, 22, 8},
        {16, 11, 11, 9, 22},
        {3, 2, 33, 11, 9}
    };

    int p[P_R][P_C] =
    {
        {9, 22, 8},
        {11, 9, 22},
        {33, 11, 9}
    };

    struct Point arr[M_R * M_C];
    int indexArr = 0;

    int p_r = P_R;
    int p_c = P_C;
    int start_r = 0;
    int start_c = 0;

    while (start_r + p_r <= M_R && start_c + p_c <= M_C)
    {
        compareSubMatrix(m, p, start_r, start_c, &arr, &indexArr);

        if (start_r + p_r < M_R)
            start_r++;
        else
        {
            start_r = 0;
            start_c++;
        }
    }

    for (int i = 0; i < indexArr; i++)
        printf("Trovata alle coordinate (%d, %d)\n", arr[i].x, arr[i].y);

    return 0;
}

//Lento
int compareSubMatrix(int m[M_R][M_C], int p[P_R][P_C], int s_r, int s_c, struct Point* pt, int* indexArr)
{
    int isEquals = 0;

    for (int i = s_r; i < s_r + M_R - P_R && !isEquals; i++)
    {
        for (int j = s_c; j < s_c + M_C - P_C && !isEquals; j++)
        {
            isEquals = 1;
            for (int a = 0; a < P_R && isEquals; a++)
            {
                for (int b = 0; b < P_C && isEquals; b++)
                {
                    if (m[a + i][b + j] != p[a][b])
                        isEquals = 0;
                }
            }

            if (isEquals)
            {
                int insert = 1;

                for (int k = 0; k < *indexArr; k++)
                {
                    if (pt[k].x == i &&
                        pt[k].y == j)
                        insert = 0;
                }

                if (insert)
                {
                    pt[*indexArr].x = i;
                    pt[*indexArr].y = j;
                    (*indexArr)++;
                }
            }
        }
    }

    return isEquals;
}