#include<stdio.h>
#include<stdlib.h>
#define size 100
struct node
{
    int data[size];
    int top;
};
void push(struct node *sptr, int num);
int pop(struct node *sptr);
int main()
{
    struct node *sptr;
    struct node s;
    sptr=&s;
    sptr->top=-1;
    int n,num;
    FILE *fp;
    FILE *fptr;
    fp=fopen("stackread.txt","r");
    fptr=fopen("stackwrite.txt","w");
    rewind(fp);
    while(fp!=EOF)
    {
        fscanf(fp,"%d",&num);
        push(sptr,num);
    rewind(fp);
    while(fp!=EOF)
    {
        num=pop(sptr);
        fprintf(fptr,"%d",num);
        fprintf(fptr,"\n");
    }
    fclose(fp);
    fclose(fptr);
}
void push(struct node *sptr, int num)
{
    if(sptr->top==size-1)
    {
        printf("node Overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=num;
    }
}
int pop(struct node *sptr)
{
    int num;
    if(sptr->top==-1)
    {
        printf("node underflow\n");
    }
    else
    {
        num=2*sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}
