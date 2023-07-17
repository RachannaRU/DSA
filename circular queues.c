#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 5

struct queue{
    int data[SIZE];
    int front,rear;
};

void enqueue(struct queue *qptr,int num)
{
    if(qptr->rear==-1&&qptr->front==-1)
    {
        qptr->front=qptr->rear=0;
        qptr->data[qptr->rear]=num;
    }
    else if((qptr->rear+1)%SIZE==qptr->front)
        printf("Queue Overflow\n");
    else
    {
        qptr->rear=(qptr->rear+1)%SIZE;
        qptr->data[qptr->rear]=num;
    }
}


int dequeue(struct queue *qptr)
{
    int num;
    if(qptr->front==-1&&qptr->rear==-1)
        num=INT_MAX;
    else if(qptr->front==qptr->rear)
    {
        num=qptr->data[qptr->front];
        qptr->front=qptr->rear=-1;
    }
    else
    {
        num=qptr->data[qptr->front];
        qptr->front=(qptr->front+1)%SIZE;
    }
    return num;
}




void display(struct queue *qptr)
{
    int i;
    if(qptr->front==-1&&qptr->rear==-1)
        printf("Queue is Empty\n");
    else if(qptr->front<=qptr->rear)
    {
        printf("Circular Queue Elements are:\n");
        for(i=qptr->front;i<=qptr->rear;i++)
            printf("%d",qptr->data[i]);
    }
    else
    {
        printf("Circular Queue Elements are:\n");
        for(i=qptr->front;i<SIZE;i++)
            printf("%d",qptr->data[i]);
        for(i=0;i<=qptr->rear;i++)
            printf("%d",qptr->data[i]);
    }
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
                else
                    printf("Queue Underflow\n");
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
    return 0;
}
