#include<stdio.h>
#include<stdlib.h>
#define size 100
int queue[size],front=-1,rear=-1;
FILE *fp;
void Random()
{

    int up,low,total;
    printf("Enter the Range of numbers and Total numbers to generate\n");
    scanf("%d%d%d",&low,&up,&total);
    for(int i=0;i<total;i++)
    {
      fprintf(fp,"%d\n",(rand()%(up-low))+low);
    }
    rewind(fp);
}
void enqueue(int queue[],int num)
{
    if(rear==size-1)
    printf("Queues is full\n");
    else
    {
        rear++;
        queue[rear]=num;
    }
}
int dequeue(int queue[])
{
    int num;
    if(front==rear)
        printf("Queue is empty\n");
    else
    {
        front++;
        num=queue[front];
    }
    return num;
}
void display(int queue[])
{
    if(front==rear)
        printf("Queue is empty\n");
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}
int main()
{
    fp=fopen("practice.txt","w");
    Random();
    int ch,num;
    while(1)
    {
        printf("\nEnter the operation\n1.Enqueue \n2.Dequeue \n3.display \n4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:fscanf(fp,"%d",&num);
                   enqueue(queue,num);break;
            case 2:num=dequeue(queue);
                   printf("Dqueued the number %d\n",num);break;
            case 3:display(queue);break;
            case 4:exit(0);
        }

    }
    fclose(fp);
}
