#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main() {
    int size = 0, *arr = NULL, **narr = NULL, *narrB = NULL, *farr = NULL, amount=0, operation=0;
    double time=0;
    printf("Input SIZE of array: ");
    size=sizeOfArray(size);
    arr=memory(arr, size);
    operation=pInputArray(operation);
    arr=inputArray(arr, size, operation);
    printf("\nArray:\n");
//    outputArray(arr, size);
    printf("\n");
    amount=amountNum(arr, size, amount);
    narr=memoryTwo(narr, 2, amount);
    narr=inputNewArray(arr, narr, size);
    narrB=memory(narrB, amount);
    narrB=inputNewArrayB(arr, narrB, size);
//    printf("Time Shell: ");
    time=timeShell(narrB, amount, time);
    outputTime(time);
    printf("\n");
    time=timeBuble(narr, amount, time);
    printf("Time: %.6lf", time);
    printf("\n\n");
    farr=memory(farr, size);
    farr=changeArray(arr, narr, farr, size, amount);
//    outputArray(farr, size);
    narr=reBuble(narr, amount);
    printf("\n");
//    printf("\nArray REBUB:\n");
//    outputTwoArray(narr, 2, amount);
//    narr=timeBuble(narr, amount, time);
//    printf("\n");
////    printf("\nArray ReBubl:\n");
////    outputTwoArray(narr, 2, amount);
    cleaning(arr);
    cleaningTwo(narr, 2);
    cleaning(narrB);
    cleaning(farr);
    return 0;
}

