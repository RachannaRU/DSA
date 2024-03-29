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

// A utility function to get the height of the tree
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
    // if true return a orelse b
}

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct node *newNode(int key)
{
    struct node *node = (struct node *)
        malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially added at leaf
    return (node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = y->left->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    else
        return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct node *insert(struct node *node, int key)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node *deleteNode(struct node *root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
    {
        printf("No element found\n");
        return root;
    }

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is
    // the node to be deleted
    else
    {
        // node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else               // One child case
                *root = *temp; // Copy the contents of
                               // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            struct node *temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
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

/* Driver program to test above function*/
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
    /* The constructed AVL Tree would be
                30
            / \
            20 40
            / \	 \
        10 25 50
    */

    FILE *fp1 = fopen("preorder.txt", "w");
    preOrder(root);
    printf("\nEnter the number to delete:\n");
    scanf("%d", &n);
    root = deleteNode(root, n);
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
