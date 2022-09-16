#include <stdio.h>

int main ()
{
    float a, x;
    
    printf("Input a=");
    while (scanf("%f", &a) !=1)
    {
        printf("Error.\tInput a=");
        rewind(stdin);
    }
    
    while(a<=1000000)
    {
        a=a*a+1;
    }
    x=a;
    printf("X=%.2f\n", x);
    return 0;
}
