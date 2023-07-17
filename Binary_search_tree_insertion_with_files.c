#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE *fp,*pre,*post,*in;
struct node
{
    int num;
    struct node *l,*r;
};
typedef struct node* NODE;
int Random()
{
    int n;
    printf("Enter the number of Random numbers to generate\n");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        fprintf(fp,"%d\n",(rand()%(100-1))+1);
    }
    rewind(fp);
    return n;
}
NODE newnode(int key)
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->num=key;
    temp->l=temp->r=NULL;
    return temp;
}

NODE insert(NODE root,int n)
{
    if(root==NULL)
        return newnode(n);
    if (n < root->num)
        root->l= insert(root->l,n);
    else if (n > root->num)
        root->r = insert(root->r,n);
    return root;

}
void preorder(NODE root)
{
    if(root==NULL)
        return;
    printf("%d ",root->num);
    fprintf(pre,"%d\n",root->num);
    preorder(root->l);
    preorder(root->r);
}
void inorder(NODE root)
{
    if(root==NULL)
        return;

    inorder(root->l);
    printf("%d ",root->num);
    fprintf(in,"%d\n",root->num);
    inorder(root->r);
}
void postorder(NODE root)
{
    if(root==NULL)
        return;
    postorder(root->l);
    postorder(root->r);
    printf("%d ",root->num);
    fprintf(post,"%d\n",root->num);
}
int main()
{
    srand(time(NULL));
    NODE root=NULL;
    fp=fopen("sorting.txt","w+");
    pre=fopen("preorder.txt","w");
    post=fopen("postorder.txt","w");
    in=fopen("inorder.txt","w");
    int num;
    int n=Random();
    fscanf(fp,"%d",&num);
    root=insert(root,num);
    for(int i=0; i<n; i++)
    {
        fscanf(fp,"%d",&num);
        insert(root,num);
    }

    printf("\nPre order is:");
    preorder(root);
    printf("\nPost order is:");
    postorder(root);
    printf("\nIn order is:");
    inorder(root);
}
