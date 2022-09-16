#include <stdio.h>
#include <math.h>

int main()
{
       float x1, y1, x2, y2, x3, y3, AB, BC, AC;
    
    printf("Input X of the first side=");
     while(scanf("%f", &x1) !=1)
     {
         printf("Error.\tInput X of the first side=");
         rewind(stdin);
     }
    
    printf("Input Y of the first side=");
     while(scanf("%f", &y1) !=1)
     {
         printf("Error.\tInput Y of the first side=");
         rewind(stdin);
     }
    
    printf("Input X of the second side=");
     while(scanf("%f", &x2) !=1)
     {
         printf("Error.\tInput X of the second side=");
         rewind(stdin);
     }
    
    printf("Input Y of the second side=");
     while(scanf("%f", &y2)!=1)
     {
         printf("Error.\tInput Y of the second side=");
         rewind(stdin);
     }
    
    printf("Input X of the third side=");
     while(scanf("%f", &x3) !=1)
     {
         printf("Error.\tInput X of the third side=");
         rewind(stdin);
     }
    
    printf("Input Y of the third side=");
     while(scanf("%f", &y3) !=1)
     {
         printf("Error.\tInput Y of the third side=");
         rewind(stdin);
     }
    
       AB =sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
       BC =sqrt(pow(x3-x2, 2)+pow(y3-y2, 2));
       AC =sqrt(pow(x3-x1, 2)+pow(y3-y1, 2));
       
    float a, b, c;
    
       a=pow(AB, 2);
       b=pow(BC, 2);
       c=pow(AC, 2);
    if (c==a==b)
    {
        printf("\nIt's not a triangle\n");
    }
    if (c==a+b)
    {
        printf("\nIt's triangle rectangular\n");
    }
    if (c>a+b)
    {
        printf("\nIt's triangle obtuse\n");
    }
    if (c<a+b)
    {
        printf("\nIt's triangle acute\n");
    }
return 0;
}
