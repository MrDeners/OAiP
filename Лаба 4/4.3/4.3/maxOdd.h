void MaxOdd(int sizei, int sizej, int arr[100][100])
{
int fl = 0, MaxOdd=-2147483648, NumOdd=-2147483648, count=1;
    if (sizei!=sizej)
        printf("The matrix is ​​not square.\n");
    else {
        if (sizei%2!=0)
            sizei++;
        int polsizei=sizei/2;
    for(int i=0; i<sizei; i++) {
        for(int b=i; b<sizei; b++) {
            for(int j=b-fl; j<polsizei; j++) {
                if(arr[b][j]%2!=0)
                    NumOdd=arr[b][j];
                if(NumOdd>MaxOdd)
                    MaxOdd=NumOdd;
                break;
            }
        }
        fl++;
        count++;
        if (count==2) {
            polsizei--;
            count=0;
        }
    }
        if(MaxOdd==-2147483648)
            printf("\nThere are no odd elements.\n");
        else
        printf("\nMaximum odd number: %d\n", MaxOdd);
    }
}
