#include<stdio.h>
int fact(int n)
{
     int f;
    if(n==1)
        return 1;
    f=n*fact(n-1);
    return f;
}
void main()
{
    int n=5;
    printf("%d",fact(n));
}
