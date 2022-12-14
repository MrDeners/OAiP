#include <stdio.h>
#include <stdlib.h>

void changeCol(int sizei, int sizej, int ChangeCol, float arr[100][100]);
for(int i = 0; i<sizei; i++) {
    for(int j = 0; j<sizej; j++) {
        if (j==ChangeCol)
            arr[i][j]/=2;
    }
}
for(int i=0; i<sizei; i++) {
    for(int j=0; j<sizej; j++) {
        printf("%.1f\t", arr[i][j]);
        if (j==sizej-1)
            printf("\n");
    }
}
printf("\n");
}

