#include<stdio.h>

int main()
{
    int x, a, b, c;
    for (x = 401; x < 500; x++)
    {
        
        a=x/100;
        b=(x-400)/10;
        c=x%10;
    if (a+b+c==9 && (c*100+b*10+a)*47/36==x)
        printf("Search number: %d\n", x);
    }
    return 0;
}

