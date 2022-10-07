#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int arr[100];
int size;
    printf("Input array size: ");
    while (scanf("%d", &size) !=1)
    {
        printf ("Error. Input number.\nInput array size: ");
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
      for(int i=last_zero; i<size; i++)
          sum=sum+arr[i];
          printf("Number of positive members: %d\n", kolvo);
          printf("Sum of numbers after the last zero: %d\n\n", sum);
          return 0;
      }
    else
      {
       printf("Error. Array size exceeded.\n");
      return 0;
      }
}
