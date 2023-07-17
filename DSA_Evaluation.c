
#include<stdio.h>
#include<stdlib.h>
#define size 100
int stack1[size],stack2[size],stack3[size]; // Creating 3 stacks or 3 players
int top1=-1,top2=-1,top3=-1;
FILE *fp,*f;
void Random(int num)
{
    int up,low;
    printf("Enter the range of numbers, lowest value and highest value\n");
    scanf("%d%d",&low,&up);
    for(int i=0;i<num;i++)
    {
        fprintf(fp,"%d\n",(rand()%(up-low))+low);
    }
}
void push(int stack1[],int stack2[],int stack3[])
{
    int x,y,z;
    fscanf(f,"%d",&x);
    top1++;
    stack1[top1]=x;

    fscanf(f,"%d",&y);
    top2++;
    stack2[top2]=y;

    fscanf(f,"%d",&z);
    top3++;
    stack3[top3]=z;

}
void pop(int stack1[],int stack2[],int stack3[])
{
    if(stack1[top1]<stack2[top2])
    {
        if(stack1[top1]<stack3[top3])
        {
          top1--;
        }
    }
     else if(stack2[top2]<stack1[top1])
    {
        if(stack2[top2]<stack3[top3])
        {
          top2--;
        }
    }
     else if(stack3[top3]<stack1[top1])
    {
        if(stack3[top3]<stack2[top2])
        {
          top3--;
        }
    }

}
void display(int stack1[],int stack2[],int stack3[])
{
     printf("Stack 1\n");
    while(top1!=-1)
    {
        printf("%d ",stack1[top1]);
        top1--;
    }
    printf("\nStack 2\n");
     while(top2!=-1)
    {
        printf("%d ",stack2[top2]);
        top2--;
    }
     printf("\nStack 3\n");
     while(top3!=-1)
    {
        printf("%d ",stack3[top3]);
        top3--;
    }
}
int main()
{
    int num;
    fp=fopen("DSA_evaluation.txt","w");
    printf("Enter the number of elements to be the size\n");
    scanf("%d",&num);
    Random(3*num);
    fclose(fp);
    f=fopen("DSA_evaluation.txt","r");
    for(int i=0;i<num;i++)
    {
        push(stack1,stack2,stack3);
    }
    display(stack1,stack2,stack3);
    while(top1!=-1&&top2!=-1&&top3!=-1)
    {
        pop(stack1,stack2,stack3);
    }
    if(top1==-1)
        printf("\nStack 1 is the winner");
    else if(top2==-1)
        printf("\nStack 2 is the winner");
    else if(top3==-1)
        printf("\nStack 3 is the winner");
        fclose(f);
}
