#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int arr[100];
int size;
    printf("Input array size: ");
    while (scanf("%d", &size) !=1 || size<0 || size>100)
           {
        printf("Error. Input number. Number > 0\nInput array size: ");
        rewind (stdin);
    }
    if (size<=100)
    {   int operation;
        printf("Choose an operation:\n1: Random\n2: Keyboard\nSelected operation: ");

               while (!scanf("%d", &operation) || operation<1 ||operation>2 )
               {
                       printf("Error.\tInput number: \n");
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
        printf("Input %d numbers clicking ENTER:\n", size);
      for(int i=0; i<size; i++)
          while(scanf("%d", &arr[i]) !=1)
          {
              printf("Error. Input number.\n");
              rewind(stdin);
          }
                break;
        }
        }
    int povtor = 0, povtor_top = 0, el = 0, flag;
        for (int i = 0; i < size; i++)
         {
            for (int j = i; j < size; j++)
            {
              if (arr[i] == arr[j] && arr[i] % 2 == 0)
              {
                povtor++;
              }
            }
            if (povtor > povtor_top)
            {
              povtor_top = povtor;
              el = arr[i];
            }
             if (povtor==povtor_top && povtor>1)
             {
                 el=arr[i];
                 printf("Several even elements are repeated.\nOne of them: %d\n", el);
                 flag++;
             }
            povtor = 0;
          }
        if (povtor_top==1)
        printf("\nNo repeating even element\n");
        if (povtor_top!=1 && flag==0)
          printf("\nMost common even element: %d\n", el);
          return 0;
        }
