//26/10/23

#include <stdio.h>

void printYDescription(int);

int main()
{
    int y;
    char ch = 's';
    
    do
    {
        printf("Anno: ");
        scanf("%d", &y);
    
        printYDescription(y);
    
        printf("Continuare? [s/n]\n");
        scanf(" %c", &ch);
    
    } while(ch == 's');
    
    return 0;
}

void printYDescription(int y)
{
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        printf("Bisestile");
    else 
        printf("Non bisestile");
        
    printf("\n");
}
