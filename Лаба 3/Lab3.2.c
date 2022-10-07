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
    {
        size++;
        int operation;
        printf("Choose an operation:\n1: Random\n2: Keyboard\nSelected operation: ");

               while (!scanf("%d", &operation) || operation>2 || operation<1)
               {
                       printf("\nError.\tInput number: ");
                       rewind(stdin);
                   }
        switch (operation)
        {
            case 1:
                for(int i=0; i<size-1; i++)
                {
                    arr[i]=rand()%201-100;
                printf("%d\n", arr[i]);
                }
                arr[size]=0;
                break;
            case 2:
                size--;
        printf("Input %d numbers clicking ENTER:\n", size);
                size++;
                arr[size]=0;
      for(int i=0; i<size-1; i++)
          while(scanf("%d", &arr[i]) !=1)
          {
              printf("Error. Input number.\n");
              rewind(stdin);
          }
                break;
        }
        int k;
        printf("Input the object number in the array: ");
        while(scanf("%d", &k) !=1)
     {
         printf("Error. Input number.\n");
         rewind(stdin);
     }
        for (int i=size-1; i>=k; i--)
            arr[i]=arr[i-1];
        arr[k-1]=0;
        for (int i=0; i<size; i++)
            printf("%d ", arr[i]);
        printf("\n");
      }
    else
      {
       printf("Error. Array size exceeded.\n");
      return 0;
      }
}

