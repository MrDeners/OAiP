#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "operation.h"
#include "maxOdd.h"

int main () {
    int arr[100][100], sizei, sizej;
    printf("Enter the number of lines (<100): ");
    while (scanf("%d", &sizei) !=1 || sizei<=0 || sizei>100 || getchar() !='\n') {
        printf ("Error. Input number. Number > 0\nEnter the number of lines (<100): ");
        rewind (stdin);
    }
    printf("Enter number of columns (<100): ");
    while (scanf("%d", &sizej) !=1 || sizej<=0 || sizej>100 || getchar() !='\n') {
        printf ("Error. Input number. Number > 0\nEnter number of columns: ");
        rewind (stdin);
    }
    operetion(sizei, sizej, arr);
    MaxOdd(sizei, sizej, arr);
    return 0;
}
