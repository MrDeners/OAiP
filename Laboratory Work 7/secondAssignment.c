#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "secondAssignment.h"


void secondAssignment (void) {
    char *arr = NULL, *sarr = NULL;
    int memorySt=0, numOfElementsSub = 0, numOfElements = 0;
    arr = memorySecond (arr, memorySt);
    arr = inputStringSecond (arr, memorySt);
    sarr = memorySecond (sarr, memorySt);
    sarr = inputSubstring (sarr, memorySt);
    numOfElements = searchNumOfElementsArray (arr);
    numOfElementsSub = searchNumOfElementsSub (sarr, numOfElementsSub);
    arr = changMainString (arr, sarr, numOfElementsSub, numOfElements);
    arr=finalReallocationSecond (arr, numOfElements);
    printf("\nFinal array:\n");
    outputStringSecond (arr);
    printf("\n");
    cleaningSecond(arr);
}

char* memorySecond (char *arr, int memorySt) {
        arr=(char*)calloc(pow(2, memorySt), sizeof(char));
    return arr;
}

char* reallocationSecond(char *arr, int memorySt) {
    arr=(char*)realloc(arr, pow(2, memorySt)*sizeof(char));
    return arr;
}

void printInputStringSecond(void) {
    printf("Input string: ");
}

void printInputSubstring(void) {
    printf("Input substring: ");
}

char* inputStringSecond (char *arr, int memorySt) {
    printInputStringSecond();
    int index=0;
    getchar();
    while((arr[index]=getchar())!='\n') {
        if (index>=(pow(2, memorySt))-1) {
            memorySt++;
            arr = reallocationSecond(arr, memorySt);
        }
        index++;
    }
    arr[index+1]='\n';
    arr[index]=' ';
    return arr;
}

char* inputSubstring (char *arr, int memorySt) {
    printInputSubstring();
    int index=0;
    getchar();
    while((arr[index]=getchar())!='\n') {
        if (index>=(pow(2, memorySt))-1) {
            memorySt++;
            arr = reallocationSecond(arr, memorySt);
        }
        index++;
    }
    arr[index+1]='\n';
    arr[index]=' ';
    return arr;
}

int searchNumOfElementsArray (char* arr) {
    int numOfElements=0;
    for (int i=0; arr[i]!='\n'; i++)
        numOfElements++;
    return numOfElements;
}

int searchNumOfElementsSub (char* sarr, int numOfElementsSub) {
    for (int i=0; sarr[i]!='\n'; i++)
        numOfElementsSub++;
    return numOfElementsSub;
}

char* changMainString (char *arr, char *sarr, int numOfElementsSub, int numOfElements) {
    int element=1, count=1, countTwo=0, fl2=numOfElements;
    for(int i=0; i<numOfElements; i++) {
        if (arr[i]==sarr[0]) {
            countTwo=1;
            for (int j=i+1; j<(i+numOfElementsSub); j++) {
                if (arr[j]!=sarr[element]) {
                    count=1;
                    element=1;
                    break;
                }
                count++;
                element++;
            if (count==(numOfElementsSub-1)) {
                for (int fl=(numOfElementsSub-1); fl>0; fl--) {
                    for (int k=i; k<fl2; k++) {
                        arr[k]=arr[k+1];
                    }
                    fl2--;
                }
                return arr;
            }
            }
        }
        if (countTwo==1 && numOfElementsSub==2) {
                for (int k=i; k<fl2; k++) {
                    arr[k]=arr[k+1];
            }
            return arr;
        }
    }
    return arr;
}

char* finalReallocationSecond (char *arr, int numOfElements) {
    numOfElements=searchNumOfElementsArray (arr);
    arr=(char*)realloc(arr, (numOfElements+1)*sizeof(char));
    return arr;
}

void outputStringSecond (char* arr) {
    int index=0;
    while(arr[index]!='\n') {
        putchar(arr[index]);
        index++;
    }
}

void cleaningSecond(char* arr) {
    free(arr);
}
