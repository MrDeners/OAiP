#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main () {
    int size = 0, *arr = NULL, minNum=2147483647, fl=0, a=0;
    printf("Input amount size of array: ");
    size=sizeOfArray(size);
    a=size;
    printf("Input %d number of array by pressing SPACE:", size);
    printf("\n");
    arr=memory(arr, size);
    arr=createArray(arr, size);
    printf("\n");
    printf("Array:\n");
    watchArray(arr, size);
    minNum=searchMin(arr, size, minNum);
    printf("\n\n");
    printf("Minimum number: %d\n", minNum);
    size=changeArray(arr, size, minNum, fl);
    arr=reallocation(arr, size);
    printf("\n");
    availability(size);
    printf("\n");
    watchArray(arr, size);
    printf("\n");
    cleaning(arr, size);
    return 0;
}
