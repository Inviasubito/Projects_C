/******************************************************************************

27/10/23
Alessandro Di ROberto

Calcolo della media

*******************************************************************************/
#include <stdio.h>
#define len 10

int main()
{
    float sum = 0;
    
    for(int i = 0; i < len; i++)
    {
        int v;
        
        printf("Value: ");
        scanf("%d", &v);
    
        sum += v;
    }
    
    printf("%f", sum / len);

    return 0;
}
