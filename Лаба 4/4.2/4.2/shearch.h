#include <stdio.h>

int searchLine(int sizei, int sizej, float arr[100][100], int ChangeCol) {
    int counter = 0;
    for(int i = 0; i<sizei; i++) {
        for(int j = 0; j<sizej; j++) {
            if(arr[i][j]==0)
                counter++;
        }
        if (counter==sizej) {
            printf("First null line: %d\n\n", i+1);
            ChangeCol=i;
            break;
        }
        else
            counter=0;
    }
