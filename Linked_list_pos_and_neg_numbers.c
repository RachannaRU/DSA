#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node *N;
N head=NULL;
N head1=NULL;
N head2=NULL;
N temp,newnode;
FILE *fp,*f;
int Random()
{
    int lower,upper,i;
    fp=fopen("sorting.txt","w+");
    printf("Enter the lower,upper and amount of numbers\n");
    scanf("%d %d %d",&lower,&upper,&i);
    for(int j=0;j<i;j++)
        fprintf(fp,"%d ",(rand()%(upper-lower+1))+lower);
    rewind(fp);
    return i;
}
N createnode()
{
    newnode=(N)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("No memory allocation\n");
        exit(0);
    }
    return (newnode);
}
N insertend(N h,int num)
{
    newnode=createnode();
    newnode->data=num;
    newnode->link=NULL;
    if(h==NULL)
     {
         h=newnode;
     }
    else
    {
        temp=h;
        while(temp->link!=NULL)
           temp=temp->link;
        temp->link=newnode;
    }
    return h;
}
void display(N h)
{
    if(h==NULL)
    {
        printf("LL is empty\n");
        exit(0);
    }
    else
    {
        temp=h;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
    }
    printf("\n\n");
}
int main()
{
    int n;
    n=Random();
    int num;
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d\n",&num);
        head=insertend(head,num);
    }
    display(head);
  N  temp1=head;
    while(temp1!=NULL)
    {
        if((temp1->data)<0)
        {

              head1=insertend(head1,temp1->data);
        }

        else
        {
            head2=insertend(head2,temp1->data);
        }

        temp1=temp1->link;
    }
    display(head1);
    display(head2);

    fclose(f);
}
