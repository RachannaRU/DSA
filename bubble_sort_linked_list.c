#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node
{
  int data;
  struct node* link;
};
typedef struct node *NODE;
NODE head;
NODE insertend(NODE head,int b);
NODE createnode(int b);
NODE display(NODE head);
NODE sort(NODE head,int a);
int main()
{
 clock_t start,stop;
 double t;
    int a,b;
    FILE *fptr;
    fptr=fopen("sort1.txt","w");
    fscanf(fptr,"%d",&a);
    for(int i=0;i<=a;i++)
    {
        fscanf(fptr,"%d",&b);
        head=insertend(head,b);
    }

    start=clock;

    head=sort(head,a);
    stop=clock;
    t=(double)(((stop-start))/CLOCKS_PER_SEC);
    printf("The cpu time used is %lf",t);
    fclose(fptr);
}
NODE insertend(NODE head,int b)
{
    NODE newnode=createnode(b);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}
NODE createnode(int b)
{
    NODE newnode=(NODE)malloc(sizeof(struct node));
    newnode->data=b;
    newnode->link=NULL;
    return newnode;
}
NODE display(NODE head)
{
    NODE ptr=head;
    while(ptr->link!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }
    return head;
}
NODE sort(NODE head,int a)
{

    int temp;
    NODE next=head;
    for(int i=0;i<a-1;i++)
    {


     while(next->link->link!=NULL)
     {
        if(next->data<next->link->data)
        {
            temp=next->data;
            next->data=next->link->data;
            next->link->data=temp;
        }
        next=next->link;
     }
     next=head;
    }
    printf("\n");

     head=display(head);

}
