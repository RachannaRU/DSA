#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 30

struct queue{
    int data[SIZE];
    int front,rear;
};

void enqueue(struct queue *qptr,int num)
{
    if(qptr->rear==SIZE-1)
        printf("Queue Overflow\n");
    else
    {
        qptr->rear++;
        qptr->data[qptr->rear]=num;
    }
}

int dequeue(struct queue *qptr)
{
    int num;
    if(qptr->front==qptr->rear)
    {
        printf("Queue Underflow\n");
        num=INT_MAX;
    }
    else
    {
        qptr->front++;
        num=qptr->data[qptr->front];
    }
    return num;
}

void display(struct queue *qptr)
{
    if(qptr->front==qptr->rear)
        printf("Queue Empty\n");
    else
        for(int i=qptr->front+1;i<=qptr->rear;i++)
            printf("%d ",qptr->data[i]);
    printf("\n");
}


int main()
{
    struct queue *qptr,q;
    qptr=&q;
    qptr->front=qptr->rear=-1;
    int ch,num,d;
    while(1)
    {
        printf("\n\nEnter your choice\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter Data to Enqueue\n");
                scanf("%d",&num);
                enqueue(qptr,num);
                break;
            case 2:
                d=dequeue(qptr);
                if(d!=INT_MAX)
                    printf("Dequeued %d\n",d);
                break;
            case 3:
                display(qptr);
                break;
            case 4:
                exit(0);
            default:
                printf("Enter Valid Choice\n");
        }
    }
}
