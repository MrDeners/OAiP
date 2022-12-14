#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int operetion(int sizei, int sizej, int arr[100][100]) {
int operation;
        printf("Choose an operation:\n1: Random\n2: Keyboard\nSelected operation: ");
               while (!scanf("%d", &operation) || operation<1 || operation>2 || getchar() !='\n') {
                       printf("Error.\tChoose an operation (1 or 2): ");
                       rewind(stdin);
                   }
        switch (operation) {
            case 1:
                srand(time(NULL));
                for(int i=0; i<sizei; i++) {
                    for(int j=0; j<sizej; j++) {
                        arr[i][j]=rand()%20-9;
                    }
                }
                break;
            case 2:
                for(int i=0; i<sizei; i++) {
                    for(int j=0; j<sizej; j++) {
                      printf("Input %dx%d number: ", i+1, j+1);
                      while(!scanf("%d", &arr[i][j])) {
                              printf("Error. Input number.\n");
                              rewind(stdin);
                      }
                    }
                }
                printf("\n");
                break;
                
                    }
    for(int i=0; i<sizei; i++) {
        for(int j=0; j<sizej; j++) {
            printf("%d\t", arr[i][j]);
            if (j==sizej-1)
                printf("\n");
                }
            }
    printf("\n");
    return arr;
}
