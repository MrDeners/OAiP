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

int** memory(int line, int coll) {
    int **arr;
    arr=(int**)calloc(line, sizeof(int*));
    for(int i=0; i<line; i++)
        arr[i]=(int*)calloc(coll, sizeof(int));
if (arr == NULL) {
        printf("Memory allocation error");
        return 0;
    }
return arr;
}

void arrayInput(int **arr, int line, int *m) {
    for (int i = 0; i < line; i++) {
        int exit = 0;
        for (int j = 0; j < *m && exit == 0; j++) {
            printf("Input [%d][%d] element: ", i + 1,j + 1);
            while (scanf("%d", &arr[i][j]) != 1 || getchar() != '\n') {
                if (arr[i][j] == -1) {
                    break;
                }
                printf("Input [%d][%d] element: ", i + 1, j + 1);
                rewind(stdin);
            }
            if (arr[i][j] == -1) {
                exit = 1;
                
            } else {
                (*m)++;
                arr[i] = (int *) realloc(arr[i], (*m) * sizeof(int));
            }
        }
    }
}

int size(int **arr, int line) {
    int size = 1;
    for (int i = 0;; i++) {
        if(arr[line][i] != -1) {
            size++;
        }
        else {
            break;
    }
    }
    return size;
}

void arrayOutput(int **arr, int line) {
    for (int i = 0; i < line; i++) {
            for (int j = 0; j < size(arr, i); j++) {
                  if (arr[i][j] != -1)
                    printf("%5d", arr[i][j]);
            }
            printf("\n");
        }
}

int** changArray(int **arr, int line) {
    for(int i=0; i<line; i++) {
        for(int j=size(arr, i)-1; j>0; j--) {
            if ((j+1)%2==0) {
                if (arr[i][j]%2==0) {
                    for(int q=j; q<=size(arr, i); q++) {
                        arr[i][q]=arr[i][q+1];
                    }

                }
            }
        }
    }
    return arr;
}

int** reallocation(int **arr, int line) {
    for(int i=0; i<line; i++) {
        arr=(int**)realloc(arr, size(arr, i)*sizeof(int*));
    }
    return arr;
}

void cleaning(int **arr, int line) {
    for(int i=0; i<line; i++)
        free(arr[i]);
    free(arr);
}



