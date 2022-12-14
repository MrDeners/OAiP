#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

int main() {
    int **arr=NULL, **narr=NULL, **farr=NULL, line=0, coll=0, futureMaxNum=0, operation=0;
    printf("Input LINE of array: ");
    line=lineOfArray(line);
    printf("Input COLL of array: ");
    coll=collOfArray(coll);
    arr=memory(arr, line, coll);
    operation=pInputArray(operation);
    arr=inputArray(arr, line, coll, operation);
    printf("\nArray: \n");
    outputTwoArray(arr, line, coll);
    narr=memory(narr, 2, coll);
    narr=inputNewArray(arr, narr, line, coll, futureMaxNum);
    farr=memory(farr, line, coll);
    farr=changeArray(arr, narr, farr, line, coll);
    printf("\nFinal Array: \n");
    outputTwoArray(farr, line, coll);
    cleaning(arr, line);
    cleaning(narr, 2);
    cleaning(farr, line);
    return 0;
}
