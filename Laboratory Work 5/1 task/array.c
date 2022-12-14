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

int* createArray(int *arr, int size) {
    for(int i=0; i<size; i++)
        while (!scanf("%d", &arr[i]) || getchar() !='\n') {
            printf("Error.\tInput number of array: ");
            rewind(stdin);
        }
    return arr;
}

void watchArray(int *arr, int size) {
    for(int i=0; i<size; i++)
        printf("%d\t", arr[i]);
}

int searchMin(int *arr, int size, int minNum) {
    for(int i=0; i<size; i++) {
        if (arr[i]<minNum)
            minNum=arr[i];
    }
    return minNum;
}

int changeArray(int *arr, int size, int minNum, int fl) {
    for(int i=0; i<size; i++) {
        if (arr[i]==minNum) {
            for(int j=i; j<size; j++)
                arr[j]=arr[j+1];
            fl++;
        }
    }
    size=size-fl;
    return size;
}

int* reallocation(int *arr, int size) {
    arr=(int*)realloc(arr, size*sizeof(int));
    return arr;
}

void availability(int size) {
    if (size==0)
        printf("The array has been completely removed.");
    else
        printf("Final array:");
}

void cleaning(int *arr, int size) {
        free(arr);
}

