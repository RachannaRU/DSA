#include<stdio.h>
#include<stdlib.h>
#define size 100
int stack[size];
int top=0;
void push(int stack[],int num)
{
    if(top==size)
        printf("Stack overflow\n");
    else
    {
        stack[top]=num;
        top++;
    }

}
int pop(int stack[])
{
    int num;
    if(top==0)
        printf("stack underflow\n");
    else
    {
        top--;
        num=stack[top];
    }
    return num;
}
void display(int stack[])
{
    while(!top==0)
    {
        printf("%d ",stack[top]);
        top--;
    }
}
int main()
{
    int ch,num;
    FILE *fp;
    fp=fopen("stackfile.txt","r");
    while(1)
    {
        printf("\nEnter the operation\n1.PUSH \n2.POP \n3.display \n4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:fscanf(fp,"%d",&num);
                   push(stack,num);break;
            case 2:num=pop(stack);
                   printf("Popped the number %d\n",num);break;
            case 3:display(stack);break;
            case 4:exit(0);
        }
    }
}
