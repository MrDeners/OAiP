#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

int lineOfArray(int line) {
    while(!scanf("%d", &line) || line<=0 || getchar() !='\n') {
        printf("Error.\tInput line of array (>0): ");
        rewind(stdin);
    }
return line;
}

int collOfArray(int coll) {
    while(!scanf("%d", &coll) || coll<=0 || getchar() !='\n') {
        printf("Error.\tInput coll of array (>0): ");
        rewind(stdin);
    }
return  coll;
}

int** memory(int **arr, int line, int coll) {
    arr=(int**)calloc(line, sizeof(int*));
    for(int i = 0; i<line; i++)
        arr[i]=(int*)calloc(coll, sizeof(int));
    if(arr==NULL) {
        printf("Memory allocation error.");
        return 0;
    }
    return arr;
}

void keyboardInputArray(int **arr, int line, int coll) {
    for (int i = 0; i<line; i++)
        for(int j = 0; j<coll; j++)
            scanf("%d", &arr[i][j]);
}

void randomInputArray(int **arr, int line, int coll) {
    srand(time(NULL));
    for (int i = 0; i<line; i++)
        for(int j = 0; j<coll; j++) {
            arr[i][j]=rand()%20-9;
        }
}

int pInputArray(int operation) {
    printf("Choose an operation:\n1: Random\n2: Keyboard\nSelected operation: ");
           while (!scanf("%d", &operation) || operation<1 || operation>2 || getchar() !='\n') {
                   printf("Error.\tChoose an operation (1 or 2): ");
                   rewind(stdin);
               }
    return operation;
}

int** inputArray(int **arr, int line, int coll, int operation) {
    switch(operation) {
        case 1:
            srand(time(NULL));
            for (int i = 0; i<line; i++)
                for(int j = 0; j<coll; j++)
                    arr[i][j]=rand()%20-9;
            return arr;
        case 2:
            keyboardInputArray(arr, line, coll);
    }
    return arr;
}

void outputTwoArray(int **arr, int line, int coll) {
    for(int i=0; i<line; i++) {
        for(int j = 0; j<coll; j++)
            printf("%5d", arr[i][j]);
        printf("\n");
    }
}

void outputTwoArrayFirstLine(int **arr, int line, int coll) {
    int i=0;
    for(int j = 0; j<coll; j++)
        printf("%5d", arr[i][j]);
    printf("\n");
}

void outputOneArray(int *arr, int size) {
    for(int i=0; i<size; i++)
            printf("%5d", arr[i]);
        printf("\n");
}

int* memoryNewArray(int *narr, int size) {
    narr=(int*)malloc(size*sizeof(int));
    return narr;
}

int** inputNewArray(int **arr, int **narr, int line, int coll, int maxNum) {
    maxNum=-2147483648;
    int i=0;
    for(int j = 0; j<coll; j++) {
        for(int k=0; k<line; k++) {
            if(arr[k][j]>maxNum)
                maxNum=arr[k][j];
            }
        narr[0][j]=maxNum;
        narr[1][j]=j;
        maxNum=-2147483648;
    }
    return narr;
}

void shell(int **narr, int size) {
    int step=size/2;
    while (step > 0)
        {
          for (int i = 0; i < (size - step); i++)
                    {
                        int j = i;
                        while (j >= 0 && narr[0][j] < narr[0][j + step])
                        {
                            int temp = narr[0][j];
                            narr[0][j] = narr[0][j + step];
                            narr[0][j + step] = temp;
                            int tmp = narr[1][j];
                            narr[1][j] = narr[1][j + step];
                            narr[1][j + step] = tmp;
                            j--;
                        }
                    }
                    step = step / 2;
                }
}

int** changeArray(int **arr, int **narr, int **farr, int line, int coll) {
    shell(narr, coll);
    for(int i=0; i<line; i++)
        for(int j=0; j<coll; j++)
            farr[i][j]=arr[i][narr[1][j]];
    return farr;
}

void cleaning(int **arr, int line) {
    for(int i=0; i<line; i++)
        free(arr[i]);
    free(arr);
}




