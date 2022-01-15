// Binary Search Tree is  tree structure that has maximum
// two subtrees. The tree is recursive in nature.
// all elements to the left of root must be < Root
// and All elements to the right of root must be > Root
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *left, *right;
};

typedef struct node node;
typedef node *BST; // pointer to node is BST

void initBST(BST *t)
{
    *t = NULL; // point start to null
    return;
}

void insertNode(BST *t, int d)
{
    node *nn = (node *)malloc(sizeof(node)); // create a node
    if (!nn)                                 // no enough memory
        return;

    nn->data = d;
    nn->left = NULL;
    nn->right = NULL;

    // check if tree is empty
    if (*t == NULL) // if tree empty create new node
    {
        *t = nn;
        return;
    }
    // if not empty
    node *p = *t;
    while (1)
    {
        if (p->data < d)      // if data to be added(here d) is > it's parent node
        {                     // then add the data to right of parent
            if (p->right)     // check if right node exist
                p = p->right; // if not create one
            else
            {
                p->right = nn; // if yes assign new node to p->right
                return;
            }
        }

        else
        {
            // if data to be added(here d) is < it's parent node
            // then add the data to left of parent
            if (p->left)     // check if left node exist
                p = p->left; // if not create one
            else
            {
                p->left = nn; // if yes assign new node to p->left
                return;
            }
        }
    }
    return;
}

void inorder(BST t)
{
    if (!t)
        return;
    inorder(t->left);       // left
    printf("%d ", t->data); // root
    inorder(t->right);      // right
    return;
}

void preorder(BST t)
{
    if (!t)
        return;
    printf("%d ", t->data); // root
    preorder(t->left);      // left
    preorder(t->right);     // right
}

void postorder(BST t)
{
    if (!t)
        return;
    postorder(t->left);     // left
    postorder(t->right);    // right
    printf("%d ", t->data); // root
}

int countleaf(BST t)
{
    if (t == NULL) // if tree is empty
        return 0;
    // return 1 if  a node has left and right node as NULL
    if (t->right == NULL && t->left == NULL) // base condition
        return 1;
    return countleaf(t->left) + countleaf(t->right);
}

int countnodes(BST t)
{
    if (!t) // if tree empty
        return 0;
    return 1 + countnodes(t->right) + countnodes(t->left);
}

int heightofBST(BST t)
{
    int leftHeight, rightHeight;
    if (!t)
        return -1;

    leftHeight = heightofBST(t->left);
    rightHeight = heightofBST(t->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

void searchBST(BST t, int key)
{
    if (!t) // empty tree
        return;

    if (t->data == key)
    {
        printf("Found\n");
        return;
    }
    if (t->data < key) // if element is on right side
        return searchBST(t->right, key);
    else // if not on right side then element on left side
        return searchBST(t->left, key);
}

int inorderPred(BST t)
{
    while (t && t->left != NULL)
        t = t->left;
    return t->data;
}

/*void deleteNode(BST *t, int value)
{
    if (!t) // if empty tree
        return NULL;

    node *p = *t;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (value < p->data)
        return deleteNode(p->left, value);
    else if (value > p->data)
        return deleteNode(p->right, value);

    // Deletion of Node when node is found
    else
    {
        // if that node is a leaf node
        if (p->left == NULL && p->right == NULL)
        {
            free(p);
            return NULL;
        }
        //if not a leaf node
        int iPre = inorderPred(t);

    }
}*/

int main()
{
    BST t1;
    initBST(&t1);
    insertNode(&t1, 50);
    insertNode(&t1, 87);
    insertNode(&t1, 27);
    insertNode(&t1, 64);
    insertNode(&t1, 13);
    insertNode(&t1, 5);
    insertNode(&t1, 40);
    insertNode(&t1, 25);
    insertNode(&t1, 70);
    printf("Inorder traversal is: ");
    inorder(t1);
    printf("\nPreorder traversal is: ");
    preorder(t1);
    printf("\nPostorder traversal is: ");
    postorder(t1);
    printf("\nNumber of leaf nodes are: %d\n", countleaf(t1));
    printf("Total nodes are: %d\n", countnodes(t1));
    printf("Height of BST is: %d\n", heightofBST(t1));
    searchBST(t1, 5);
    return 0;
}
