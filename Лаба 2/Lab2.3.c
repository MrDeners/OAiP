#include <stdio.h>

int main()
{
    int N, a=1, b=1, c=0;
    printf("Input N=");
    while (scanf("%d", &N) !=1)
    {
        printf("Error. Input N=");
        rewind(stdin);
    }
    while(c<N+1)
    {
    a=b;
    b=c;
    c=a+b;
    }
    printf("\nFirst Fibonacci number greater than N=%d\n\n", c);
    return 0;
}

