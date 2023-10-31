/******************************************************************************

31/10/23
Alessandro Di Roberto

Si scriva un programma che riceve dallo standard input due caratteri alfabetici, li converte in maiuscolo e
stampa a video ordinatamente tutti i caratteri dell'alfabeto fra essi compresi, estremi inclusi.
Esempio: dati 'g' e 'M' stampa a video la sequenza: GHIJKLM.

*******************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main()
{
    char c1, c2;
    int u1, u2, length;

    printf("Inserisci i carateri (\"A, \"B): ");
    scanf(" %c, %c", &c1, &c2);

    u1 = (int)(toupper(c1));
    u2 = (int)(toupper(c2));

    if (u1 > u2)
    {
        int v = u1;
        u1 = u2;
        u2 = v;
    }

    length = u2 - u1;

    for (int i = 0; i <= length; i++)
        printf("%c", (char)u1++);

    return 0;
}