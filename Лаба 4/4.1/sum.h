#include <stdio.h>

void sum(int sizei, int sizej, int arr[100][100]) {
int sum = 0, maxSum=-2147483648, fl=1;
if (sizei!=sizej)
    printf("The matrix is ​​not square.\n");
else {
for(int i=1; i<sizei; i++) {
    for(int b=i; b<sizei; b++) {
        for(int j=b-fl; j<sizej; j++) {
            sum+=arr[b][j];
            break;
        }
    }
            if (sum>maxSum)
                maxSum=sum;
                sum=0;
    fl++;
}
fl=0;
for(int j=1; j<sizej; j++) {
    for(int b=0; b<sizei; b++) {
        for(int a=j+fl; a<sizej; a++) {
            sum+=arr[b][a];
            fl++;
            break;
        }
    }
fl=0;
            if (sum>maxSum)
                maxSum=sum;
                sum=0;
}
printf("\nMaximum amount: %d\n", maxSum);
}
}
