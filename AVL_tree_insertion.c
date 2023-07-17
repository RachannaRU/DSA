#include <stdio.h>
#include <stdlib.h>
#include<time.h>
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
struct node *newNode(int key)
{
    struct node *node = (struct node *)
        malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = y->left->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    return x;
}
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
    return y;
}

int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    else
        return height(N->left) - height(N->right);
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


void inorder(struct node *root, FILE *fp)
{
    if (root != NULL)
    {
        inorder(root->left, fp);
        fprintf(fp, "%d ", root->key);
        printf("%d ", root->key);
        inorder(root->right, fp);
    }
}
void preorder(struct node *root, FILE *fp)
{
    if (root != NULL)
    {
        fprintf(fp, "%d ", root->key);
        printf("%d ", root->key);
        preorder(root->left, fp);
        preorder(root->right, fp);
    }
}
void postorder(struct node *root, FILE *fp)
{
    if (root != NULL)
    {
        postorder(root->right, fp);
        postorder(root->left, fp);
        printf("%d ", root->key);
        fprintf(fp, "%d ", root->key);
    }
}

void random(FILE *fp, int n)
{
    int r;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        r = rand() % 101;
        fprintf(fp, "%d ", r);
    }
    rewind(fp);
}
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void display(struct node *ptr,int level)
{
        int i;
        FILE *fptr;
        fptr=fopen("display.txt","w");
        if(ptr == NULL )
                return;
        else
       {
                display(ptr->right, level+1);
                printf("\n");
                fprintf(fptr, "\n");
                for (i=0; i<level; i++)
                {
                    printf("    ");
                    fprintf(fptr, "    ");
                }
                printf("%d", ptr->key);
                fprintf(fptr, "%d", ptr->key);
                display(ptr->left, level+1);
        }
        fclose(fptr);
}

int main()
{
    struct node *root = NULL;
    int n;
    FILE *fp = fopen("random.txt", "w+");
    printf("Enter how many random numbers:\n");
    scanf("%d", &n);
    random(fp, n);
    for (int i = 0; i < n; i++)
    {
        int key;
        fscanf(fp, "%d", &key);
        root = insert(root, key);
    }
    fclose(fp);
    FILE *fp1 = fopen("preorder.txt", "w");
    printf("\nPreorder:\n");
    preorder(root, fp1);
    fclose(fp1);
    FILE *fp2 = fopen("inorder.txt", "w");
    printf("\ninorder:\n");
    inorder(root, fp2);
    fclose(fp2);
    FILE *fp3 = fopen("postorder.txt", "w");
    printf("\nPostorder:\n");
    postorder(root, fp3);
    fclose(fp3);
    display(root,0);
    return 0;
}
