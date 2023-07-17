#include <stdio.h>
#include <stdlib.h>
#include<time.h>
FILE *fp;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node* NODE;
NODE createNode(int value)
{
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

NODE insert(NODE root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void printNodesAtLevel(NODE root, int level)
{
    if (root == NULL)
        return;

    if (level == 1)
        printf("%d  ", root->data);
    else if (level > 1)
    {
        printNodesAtLevel(root->left, level - 1);
        printNodesAtLevel(root->right, level - 1);
    }
}

/*int getHeight(NODE root)
{
    if (root == NULL)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}*/
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
void preorder(NODE root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void display(NODE ptr,int level)
{
        int i;
        if(ptr == NULL )
                return;
        else
    {
                display(ptr->right, level+1);
                printf("\n");
                for (i=0; i<level; i++)
                        printf("    ");
                printf("%d", ptr->data);
                display(ptr->left, level+1);
        }
}
int main()
{
    srand(time(NULL));
    NODE root=NULL;
    fp=fopen("sorting.txt","w+");
    int num;
    int n=Random();
    fscanf(fp,"%d",&num);
    root=insert(root,num);
    for(int i=1;i<n;i++)
    {
        fscanf(fp,"%d",&num);
        insert(root,num);
    }
    preorder(root);
    int level = 7;
    for(int i=0;i<level;i++)
    {
    printf("\nNodes at level %d: ", i);
    printNodesAtLevel(root, i);
    printf("\n");
    }
    display(root,0);


    return 0;
}
