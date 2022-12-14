#include <stdio.h>
#include "operation.h"
#include "shearch.h"
#include "change.h"

int main() {
    float arr[100][100];
    int sizei, sizej;
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
    printf("\nResult:\n\n");
    int ChangeCol=-1;
    ChangeCol=searchLine(sizei, sizej, arr, ChangeCol);
    changeCol(sizei, sizej, ChangeCol, arr);
    return 0;
}
