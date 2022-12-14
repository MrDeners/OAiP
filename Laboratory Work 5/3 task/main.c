#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

int main() {
    int line=0, **arr=NULL, coll=1, maxLine=0;
    printf("Input amount lines of array: ");
    line=lineOfArray(line);
    coll=collOfArray(coll);
    arr=memory(arr, line, coll);
    printf("Input NUMBER of array: \n");
    arrayInput(arr, line, coll);
    printf("Array:\n");
    arrayOutput(arr, line, coll);
    printf("\nFinal array:\n");
    coll=changArray(arr, line, maxLine, coll);
    arr=reallocation(arr, line, coll);
    arrayOutput(arr, line, coll);
    cleaning(arr, line);
    return 0;
}
