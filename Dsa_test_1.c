#include<stdio.h>
int main()
{
    int x;
    char sent[100];
    FILE *f;
    f=fopen("lines.txt","r");
    fscanf(f,"%d",&x);
    if(x>10)
    {
        printf("invalid input /n");
        exit(0);
    }
    for(int i=0;i<x;i++)
    {
        fgets(sent,100,f);
        puts(sent);
    }
}
