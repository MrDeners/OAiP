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
                       printf("Error.\tInput number: \n");
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
        printf("Input %d numbers clicking ENTER:\n", size);
      for(int i=0; i<size; i++)
          while(scanf("%d", &arr[i]) !=1)
          {
              printf("Error. Input number.\n");
              rewind(stdin);
          }
                break;
        }
        int povtor = 0, povtor_top = 0, el = 0;
        for (int i = 0; i < size; i++)
          {
            for (int j = i; j < size; j++)
            {
              if (arr[i] == arr[j])
              {
                povtor++;
              }
            }
            if (povtor > povtor_top)
            {
              povtor_top = povtor;
              el = arr[i];
            }
            povtor = 0;
          }
        if (povtor_top==1)
    printf("\nSome elements repeat the same number of times.\n");
        else
          printf("\nMost common element: %d\n", el);
          return 0;
      }
    else
      {
       printf("Error. Array size exceeded.\n");
      return 0;
      }
}
