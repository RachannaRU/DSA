#include<stdio.h>
#include<stdlib.h>
#define size 100
void push(int stack,num)
{
    stack[++top]=num;
}
int pop()
{

}
int main()
{
    int top=-1,num;
    int stack[size];
    FILE* fp;
    FILE* fptr;
    fp=fopen("stackread.txt","r");
    fptr= fopen( "stackwrite.txt","w");
    while(fp!=EOF)
    {
        fscanf(fp,"%d",&num);
        push(stack,num);
    }
    rewind(fp);
    while(fp!=EOF)
    {
        fprintf(fptr,"%d\n",2*stack[top]);
        fprintf(fptr,"\n");
        top--;
    }

}
