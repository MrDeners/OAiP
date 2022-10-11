#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int arr[100];
int size;
    printf("Input array size(<100): ");
    while (scanf("%d", &size) !=1 || size<0 || size>100)
    {
        printf ("Error. Input number. Number > 0\nInput array size: ");
        rewind (stdin);
    }
    if (size<=100)
    {   int operation;
        printf("Choose an operation:\n1: Random\n2: Keyboard\nSelected operation: ");

               while (!scanf("%d", &operation) || operation<1 ||operation>2 )
               {
                       printf("Error.\tInput number: ");
                       rewind(stdin);
                   }
        switch (operation)
        {
            case 1:
                srand(time(NULL));
                for(int i=0; i<size; i++)
                {
                    arr[i]=rand()%201-100;
                printf("%d\n", arr[i]);
                }
                break;
            case 2:
        printf("Input %d numbers clicking ENTER: \n", size);
      for(int i=0; i<size; i++)
          while(scanf("%d", &arr[i]) !=1)
          {
              printf("Error. Input number.\n");
              rewind(stdin);
          }
                break;
        }
          int kolvo=0;
      for(int i=0; i<size; i++)
          if (arr[i]>0)
              kolvo++;
          int last_zero = 0, sum = 0;
      for(int i=0; i<size; i++)
          if (arr[i]==0)
              last_zero=i;
        if (last_zero==0)
            printf("\nThere is no zero in the array, so the sum is zero.\n");
        else for(int i=last_zero; i<size; i++)
          sum=sum+arr[i];
          printf("Number of positive members: %d\n", kolvo);
        if (last_zero!=0)
          printf("Sum of numbers after the last zero: %d\n\n", sum);
          return 0;
      }
}
