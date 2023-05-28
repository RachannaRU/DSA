#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node *node;

node newnode,temp;

//function prototypes
node getnode();
node read_details(node newnode);
void display(node head);
node insertend(node newnode);
node insertbeg(node newnode);
node delete_end(node newnode);
node delete_front(node newnode);
int count_nodes(node head);
void search_node(node head);
node search_and_delete(node newnode);
node insert_position(node newnode);


node head=NULL;

int main()
{
    int choice,count;
    while(1)
    {
        printf("\n1.INSERT_END\n2.DISPLAY\n3.INSERT_BEGIN\n4.DELETE_END\n5.DELETE_FRONT\n6.COUNT_NODES\n7.SEARCH_NODE\n8.SEARCH_AND_DELETE\n9.INSERT_POSITION\n10.EXIT\n");
        printf("\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            head=insertend(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            head=insertbeg(head);
            break;
        case 4:
            head=delete_end(head);
            break;
        case 5:
            head=delete_front(head);
            break;
        case 6:
            count=count_nodes(head);
            printf("Number of nodes are %d\n",count);
            break;
        case 7:
            search_node(head);
            break;
        case 8:
            head=search_and_delete(head);
            break;
        case 9:head=insert_position(head);
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}

node getnode()
{
    newnode=(node)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("No memory allocation\n");
        exit(0);
    }
    return (newnode);
}



node read_details(node newnode)
{
    printf("\nEnter int data\n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return(newnode);
}



node insertend(node newnode)
{
    newnode=getnode();
    newnode=read_details(newnode);
    if(head==NULL)
    {
        return newnode;
    }
    else
    {
        temp=head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=newnode;
        return head;
    }
}


void display(node head)
{
    if(head==NULL)
    {
        printf("LL is empty\n");
        exit(0);
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }
    }
    printf("\n\n");
}


node insertbeg(node newnode)
{
    newnode=getnode();
    newnode=read_details(newnode);
    if(head==NULL)
    {
        return newnode;
    }
    else
    {
        newnode->link=head;
        head=newnode;
        return(head);
    }
}


node delete_end(node newnode)
{
    node cur,prev;
    if(head==NULL)
    {
        printf("SLL EMPTY\n");
    }
    else if(head->link==NULL)
    {
        printf("Deleted %d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        prev=NULL;
        cur=head;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=NULL;
        printf("Deleted %d\n",cur->data);
        free(cur);
    }
    return head;
}


node delete_front(node newnode)
{
    node cur;
    if(head==NULL)
    {
        printf("SLL EMPTY\n");
    }
    else if(head->link==NULL)
    {
        printf("Deleted %d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
        head=head->link;
        printf("Deleted %d\n",cur->data);
        free(cur);
    }
    return head;
}


int count_nodes(node head)
{
    int c=0;
    node cur;
    if(head==NULL)
    {
        return c;
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            c++;
            cur=cur->link;
        }
    }
    return c;
}


void search_node(node head)
{
    int status=0,key;
    node cur;
    printf("Enter the number to search\n");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("Singly linked list empty\n");
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            if(cur->data==key)
            {
                status=1;
                break;
            }
            cur=cur->link;
        }
        if(status==1)
        {
            printf("Search Successful,%d found\n",key);
        }
        else
        {
            printf("Search Unsuccessful,%d not found\n",key);
        }
    }
}



node search_and_delete(node newnode)
{
    int status=0,key;
    node cur,prev;
    printf("Enter a number\n");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("Singly linked list empty\n");
    }
    else if(head->data==key)
    {
        head=delete_front(head);
    }
    else
    {
        prev=NULL;
        cur=head;
        while(cur!=NULL)
        {
            if(cur->data==key)
            {
                status=1;
                break;
            }
            prev=cur;
            cur=cur->link;
        }
        if(status==1)
        {
            prev->link=cur->link;
            printf("Deleted %d\n",cur->data);
            free(cur);
        }
        else
        {
            printf("%d not found\n",key);
        }
    }
    return head;
}


node insert_position(node newnode)
{
    node prev, cur;
    newnode=getnode();
    newnode=read_details(newnode);
    int pos;
    int count=count_nodes(head);
    printf("Enter position\n");
    scanf("%d",&pos);
    if(pos==1&&head==NULL)
    {
        head=newnode;
    }
    else if(pos==1)
    {
        newnode->link=head;
        head=newnode;
    }
    else if(pos==count+1)
    {
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    }
    else if(pos>1&&pos<=count)
    {
        prev=NULL;
        cur=head;
        for(int i=1;i<=pos-1;i++)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=newnode;
        newnode->link=cur;
    }
    else
    {
        printf("Invalid position\n");
    }
    return head;
}
