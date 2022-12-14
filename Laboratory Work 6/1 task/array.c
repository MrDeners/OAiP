#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

int sizeOfArray(int size) {
    while (!scanf("%d", &size) || size<=0 || getchar() !='\n') {
        printf("Error.\tInput size of array (>0): ");
        rewind(stdin);
    }
    return size;
}
int* memory(int *arr, int size) {
    arr=(int*)malloc(size * sizeof(int));
    return arr;
}

int** memoryTwo(int **arr, int line, int coll) {
    arr=(int**)calloc(line, sizeof(int*));
    for(int i = 0; i<line; i++)
        arr[i]=(int*)calloc(coll, sizeof(int));
    if(arr==NULL) {
        printf("Memory allocation error.");
        return 0;
    }
    return arr;
}

void keyboardInputArray(int *arr, int size) {
    printf("\nInput %d number of array by pressing SPACE:\n", size);
    for(int i=0; i<size; i++)
        while (!scanf("%d", &arr[i]) || getchar() !='\n') {
            printf("Error.\tInput number of array: ");
            rewind(stdin);
        }

}

void randomInputArray(int *arr, int size) {
    srand(time(NULL));
    for(int i=0; i<size; i++)
            arr[i]=rand()%20-9;
}

int pInputArray(int operation) {
    printf("Choose an operation:\n1: Random\n2: Keyboard\nSelected operation: ");
           while (!scanf("%d", &operation) || operation<1 || operation>2 || getchar() !='\n') {
                   printf("Error.\tChoose an operation (1 or 2): ");
                   rewind(stdin);
               }
    return operation;
}

int* inputArray(int *arr, int size, int operation) {
    switch(operation) {
        case 1:
            srand(time(NULL));
            for(int i=0; i<size; i++)
                    arr[i]=rand()%20-9;
            return arr;
        case 2:
            keyboardInputArray(arr, size);
    }
    return arr;
}

void outputArray(int *arr, int size) {
    for(int i=0; i<size; i++)
        printf("%5d", arr[i]);
    printf("\n");
}

void outputTwoArray(int **arr, int line, int coll) {
    for(int i=0; i<line; i++) {
        for(int j = 0; j<coll; j++)
            printf("%5d", arr[i][j]);
        printf("\n");
    }
}

int amountNum(int *arr, int size, int amount) {
    for(int i=0; i<size; i++)
        if (arr[i]<0 && arr[i]%2!=0) {
            amount++;
        }
    return amount;
}

int** inputNewArray(int *arr, int **narr, int size) {
    int f=0;
    for(int i = 0; i < size; i++) {
        if (arr[i]<0 && arr[i]%2!=0) {
        narr[0][f] = arr[i];
        narr[1][f] = i;
        f++;
        }
    }
    return narr;
}

int* inputNewArrayB(int *arr, int *narrB, int size) {
    int f=0;
    for(int i = 0; i < size; i++) {
        if (arr[i]<0 && arr[i]%2!=0) {
        narrB[f] = arr[i];
        f++;
        }
    }
    return narrB;
}

void buble(int **narr, int amount) {
    for(int i=0; i<amount-1; i++)
        for(int j=0; j<amount-i-1; j++)
            if(narr[0][j]>narr[0][j+1]) {
                int temp=narr[0][j];
                narr[0][j]=narr[0][j+1];
                narr[0][j+1]=temp;
                
                temp=narr[1][j];
                narr[1][j]=narr[1][j+1];
                narr[1][j+1]=temp;
            }
}

void shell(int *arr, int size) {
    int i, j, step;
    int tmp;
    for (step=size/2; step>0; step/=2)
        for (i=step; i<size; i++)
        {
            tmp = arr[i];
            for (j=i; j>=step; j-=step)
            {
                if (tmp<arr[j - step])
                    arr[j]=arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
        }
}

double timeBuble(int **narr, int amount, double time) {
    clock_t time_start=clock();
    buble(narr, amount);
    clock_t time_end=clock()-time_start;
    time = (double)time_end/CLOCKS_PER_SEC;
//    printf("Time Buble: %f", (double)time_end/CLOCKS_PER_SEC);
    return time;
}

int* changeArray(int *arr, int **narr, int *farr, int size, int amount) {
    int f=0;
    for(int i=0; i<size; i++)
        if (arr[i]<0 && arr[i]%2!=0) {
            farr[i]=arr[narr[1][f]];
            f++;
        }
        else
            farr[i]=arr[i];
    return farr;
}

double timeShell(int *narrB, int amount, double time) {
    clock_t time_start=clock();
    shell(narrB, amount);
    clock_t time_end=clock()-time_start;
    time = (double)time_end/CLOCKS_PER_SEC;
//    printf("%f", (double)time_end/CLOCKS_PER_SEC);
    return time;
}

void outputTime(double time) {
    printf("Time: %.6lf", time);
}

int** reBuble(int **narr, int amount) {
    for(int i=0; i<amount-1; i++)
        for(int j=0; j<amount-i-1; j++)
            if(narr[0][j]<narr[0][j+1]) {
                int temp=narr[0][j];
                narr[0][j]=narr[0][j+1];
                narr[0][j+1]=temp;
                
                temp=narr[1][j];
                narr[1][j]=narr[1][j+1];
                narr[1][j+1]=temp;
            }
    return narr;
}

int** timeReBuble(int **narr, int amount) {
    clock_t time_start=clock();
    reBuble(narr, amount);
    clock_t time_end=clock()-time_start;
    printf("Time ReBuble: %f", (double)time_end/CLOCKS_PER_SEC);
    return narr;
}

void cleaning(int *arr) {
        free(arr);
}

void cleaningTwo(int **arr, int line) {
    for(int i=0; i<line; i++)
        free(arr[i]);
    free(arr);
}
