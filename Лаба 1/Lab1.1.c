#include <stdio.h>

int main ()
{
  
    float a, b, c, s, v;
    printf("Input a=");
     while (scanf("%f", &a) !=1)
     {
         printf("Error.\tInput a=");
         rewind(stdin);
     }
    
    printf("Input b=");
     while (scanf("%f", &b) !=1)
    {
        printf("Error.\tInput b=");
        rewind(stdin);
    }
    
    printf("Input c=");
     while (scanf("%f", &c) !=1)
    {
        printf("Error.\tInput c=");
        rewind(stdin);
    }
    
    s=2 * (a*b + b*c + a*c);
    v=a*b*c;
    
    printf("\nArea = %.3f\nVolume = %.3f\n\n", s, v);
    return 0;
}

