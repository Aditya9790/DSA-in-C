// Evaluating Postfix expression using stack
// We will create a stack and store the integers in stack

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

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
    int a;
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return INT_MAX;
    }
    else
    {
        SNode *temp = top; // make a temp pointer pointing to top
        top = temp->next;  // assign
        a = temp->data;
        free(temp);
    }
    return a;
}

int main()
{
    SNode s;
    char expression[] = "1 2 + 1 / 650 * 79 +";
    int len = sizeof(expression) / sizeof(char);

    int oprand1, oprand2;

    for (int i = 0; i < len - 1; i++)
    {
        if (expression[i] == ' ')
            continue;

        else if (isdigit(expression[i]))
        {
            int num = 0; // convert to a whole number
            while (isdigit(expression[i]))
            {
                num = num * 10 + (int)(expression[i] - '0');
                i++;
            }
            PushLinkedStack(&s, num);
        }
        else
        {
            oprand1 = PopLinkedStack(&s); // convert char to int by subtractinf ASCII value of 0
            oprand2 = PopLinkedStack(&s);

            switch (expression[i])
            {
            case '+':
                PushLinkedStack(&s, oprand2 + oprand1);
                break;
            case '-':
                PushLinkedStack(&s, oprand2 - oprand1);
                break;
            case '*':
                PushLinkedStack(&s, oprand2 * oprand1);
                break;
            case '/':
                PushLinkedStack(&s, oprand2 / oprand1);
                break;
            }
        }
    }
    int total = (float)(PopLinkedStack(&s));

    printf("Postfix evaluation: %d\n", total);
    return 0;
}