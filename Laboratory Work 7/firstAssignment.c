#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "firstAssignment.h"



void firstAssignment (void) {
    int memorySt=0, k=0, numOfElements=0;
    char *arr = NULL;
    arr = memory (arr, memorySt);
    k=inputK ();
    arr = inputString (arr, memorySt);
    printf("\nArray:\n");
    outputString (arr);
    numOfElements = searchNumOfElements (arr);
    arr = changeString (arr, k, numOfElements);
    arr = finalReallocation (arr, numOfElements);
    printf("\nFinal array:\n");
    outputString (arr);
    printf("\n");
    cleaning(arr);
}



char* memory (char *arr, int memorySt) {
    arr=(char*)calloc(pow(2, memorySt), sizeof(char));
    return arr;
}

char* reallocation(char *arr, int memorySt) {
    arr=(char*)realloc(arr, pow(2, memorySt));
    return arr;
}

void printInputString(void) {
    printf("Input numbers of array: ");
}

char* inputString (char* arr, int memorySt) {
    printInputString();
    int index=0;
    getchar();
    while((arr[index]=getchar())!='\n') {
        if (index>=(pow(2, memorySt))-1) {
            memorySt++;
            arr = reallocation(arr, memorySt);
        }
        index++;
    }
    arr[index+1]='\n';
    arr[index]=' ';
    return arr;
}

void printInputK (void) {
    printf("Input K: ");
}

int inputK (void) {
    int k=0;
    printInputK ();
    scanf("%d", &k);
    return k;
}

int searchNumOfElements (char* arr) {
    int numOfElements=0;
    for (int i=0; arr[i]!='\n'; i++)
        numOfElements++;
    return numOfElements;
}

char* changeString(char* arr, int k, int numOfElements) {
    int count=-1;
    for(int i=0; i < numOfElements; i++) {
        count++;
        if (arr[i]==' ') {
            if(count<k) {
                int fl2=numOfElements;
                for (int fl=count+1; fl>0; fl--) {
                    for (int j=i-count; j<fl2; j++)
                        arr[j] = arr[j+1];
                    fl2--;
                }
                i=-1;
            }
            count=-1;
        }
    }
    return arr;
}

char* finalReallocation (char *arr, int numOfElements) {
    numOfElements=searchNumOfElements (arr);
    arr=(char*)realloc(arr, (numOfElements+1)*sizeof(char));
    return arr;
}

void outputString (char* arr) {
    int index=0;
    while(arr[index]!='\n') {
        putchar(arr[index]);
        index++;
    }
}

void cleaning(char* arr) {
    free(arr);
}
