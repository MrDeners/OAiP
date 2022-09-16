#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, x1=0, y1=0, OM;
    
    printf("Input a=");
     while(scanf("%f", &a) !=1)
     {
         printf("Error.\tInput a=");
         rewind(stdin);
     }
    
    printf("Input b=");
     while(scanf("%f", &b) !=1)
     {
         printf("Error.\tInput b=");
         rewind(stdin);
     }
    
    OM =sqrt(pow(a-x1, 2)+pow(b-y1, 2));
    
if (OM>1)
 {
    printf("The point M(a,b) is not inside the top of the unit circle centered at the origin.\n");
 }
if (OM<=1)
  {
    printf("The point M(a,b) is inside the top of the unit circle centered at the origin.\n");
  }
    return 0;
}
