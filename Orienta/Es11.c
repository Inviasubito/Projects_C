/******************************************************************************

31/10/23
Alessandro Di Roberto

Si scriva un programma che legge una sequenza di caratteri (la sequenza termina quando viene
inserito il carattere "#"), conta il numero complessivo di vocali minuscole ("a", "e", "i", "o", "u") comprese
nella sequenza e stampa questo valore.
Per esempio, nel caso la sequenza in ingresso fosse
defghi123jklmaAAa002#
il programma dovrebbe stampare il valore 4.

*******************************************************************************/

#include <stdio.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 30

int GetVowelsNumber_ByStep();
int GetVowelsNumber_ByString();

int main()
{
    int v;
    printf("Scagli la modalità di inserimento: \n\t0: Steps\n\t1:Stringa\nLa tua scelta:");
    scanf("%d", &v);

    if (v)
        v = GetVowelsNumber_ByString();
    else
        v = GetVowelsNumber_ByStep();

    printf("Sono state inserite %d vocali.", v);

    return 0;
}

//Legge una intera sequenza
int GetVowelsNumber_ByString()
{
    char c[MAX_STRING_LENGTH];
    int count = 0;

    printf("Inserisci sequenza:");
    scanf("%s", &c);

    for (int i = 0; i < MAX_STRING_LENGTH; i++)
    {
        if (c[i] == 'a' ||
            c[i] == 'e' ||
            c[i] == 'i' ||
            c[i] == 'o' ||
            c[i] == 'u')
        {
            count++;
        }
        else if (c[i] == '#')
            break;
    }

    printf("Sono state inserite %d vocali.", count);

    return count;
}

//Legge carattere per carattere
int GetVowelsNumber_ByStep()
{
    char c;
    char keys[] = { 'a', 'e', 'i', 'o', 'u' };
    int count = 0;

    do
    {
        printf("Carattere: ");
        scanf(" %c", &c);

        for (int i = 0; i < 5; i++)
        {
            if (c == keys[i])
                count++;
        }

    } while (c != '#');

    return count;
}