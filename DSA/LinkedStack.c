#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct StackNode;

struct StackNode
{
    int data;
    struct StackNode *next;
};

typedef struct StackNode SNode;

SNode *top = NULL; // declare a top pointer to null

void PushLinkedStack(SNode *sn, int key) // create a head node
{
    SNode *currnode = (SNode *)malloc(sizeof(SNode));
    currnode->data = key;
    if (top == NULL) // if stack empty create a fresh node
        currnode->next = NULL;
    else
        currnode->next = top; // point next of current node to top
    top = currnode;
}

int PopLinkedStack(SNode *s)
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return INT_MAX;
    }
    else
    {
        SNode *temp = top; // make a temp pointer pointing to top
        top = temp->next;  // assign
       // printf("\n The popped element is: %d\n", temp->data);
       int a = temp->data;
        free(temp);
        return a;
    }
}

void PrintLinkedStack(SNode *s)
{
    if (top == NULL)
        printf("Stack is Empty");

    SNode *curr = top;
    while (curr->next != NULL)
    {
        printf("%d--->", curr->data);
        curr = curr->next;
    }
    printf("%d--->NULL\n", curr->data);
}

int isLinkedStackEmpty(SNode s)
{
    return top == NULL;
}

int peekLinkedStack(SNode s)
{
    SNode *temp = top;
    return temp->data;
}
/*
int main()
{
    SNode ls; // ls == Linked Stack

    PushLinkedStack(&ls, 10);
    PushLinkedStack(&ls, 20);
    PushLinkedStack(&ls, 30);
    PushLinkedStack(&ls, 40);

    printf("\nStack before popping: ");
    PrintLinkedStack(&ls);

    PopLinkedStack(&ls);

    printf("\nStack after popping: ");
    PrintLinkedStack(&ls);
    //isLinkedStackEmpty(&ls);
    printf("%d\n", peekLinkedStack(ls));
    return 0;
}*/
