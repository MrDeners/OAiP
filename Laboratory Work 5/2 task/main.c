#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

int main() {
    int line=0, **arr=NULL, m=1;
    printf("Input amount lines of array: ");
    line = lineOfArray(line);
    arr = memory(line, m);
    arrayInput(arr, line, &m);
    printf("Array:\n");
    arrayOutput(arr, line);
    changArray(arr, line);
    printf("\nFinal array:\n");
    arr=reallocation(arr, line);
    arrayOutput(arr, line);
    cleaning(arr, line);
    return 0;
}
