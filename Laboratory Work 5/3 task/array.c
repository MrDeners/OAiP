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
        printf("Error.\tInput line of array (>0): ");
        rewind(stdin);
    }
return  coll;
}

int** memory(int **arr, int line, int coll) {
    arr=(int**)calloc(line, sizeof(int*));
    for(int i = 0; i<line; i++)
        arr[i]=(int*)calloc(coll, sizeof(int));
    if(arr==NULL) {
        printf("Memory allocation error");
        return 0;
    }
    return arr;
}

void arrayInput(int **arr, int line, int coll) {
    for (int i = 0; i<line; i++)
        for(int j = 0; j<coll; j++)
            scanf("%d", &arr[i][j]);
}

void arrayOutput(int **arr, int line, int coll) {
    for(int i=0; i<line; i++){
        for(int j=0; j<coll; j++) {
            if (arr[i][j]!=-1)
                printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

int changArray(int **arr, int line, int maxLine, int coll) {
    int i=0, counter=0;
        for(int j=0; j<coll; j++) {
            if (arr[i][j]<0) {
                for(int k=0; k<line; k++) {
                    if (arr[k][j]<0)
                        counter++;
                }
                if (counter==line) {
                    for(int q=0; q<line; q++) {
                        for(int r=j; r<coll; r++) {
                            if (r==coll-1)
                                break;
                            else
                            arr[q][r]=arr[q][r+1];
                        }
                    }
                    j--;
                    coll--;
            }
            counter=0;
            }
        }
    return coll;
}

int** reallocation(int **arr, int line, int coll) {
    arr=(int**)realloc(arr, line*sizeof(int*));
    for(int i = 0; i<line; i++)
        arr[i]=(int*)realloc(arr[i], line*sizeof(int));
    return arr;
}

void cleaning(int **arr, int line) {
    for(int i=0; i<line; i++)
        free(arr[i]);
    free(arr);
}



