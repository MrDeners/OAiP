#include <stdio.h>
void mult(int sizei, int sizej, int arr[100][100]) {
    
int fl = 0, multiplication=1, counter=0;
 for(int i=0; i<sizei; i++) {
    for(int j = 0; j<sizej; j++) {
        if(arr[i][j]<0)
            fl++;
        if(j==sizej-1 && fl==0) {
            for(int j = 0; j<sizej; j++) {
                multiplication*=arr[i][j];
            }
                printf("Multiplication %d line=%d\n", i+1,  multiplication);
            counter++;
            multiplication=1;
        }
    }
     fl=0;
 }
if (counter==0)
    printf("All rows have a negative number or all numbers are equal to one.\n");
}
