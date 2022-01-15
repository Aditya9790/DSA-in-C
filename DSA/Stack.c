#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
    int *A; // integer array
    int size, top;
};

typedef struct Stack Stack;

void initStack(Stack *s, int n)
{
    s->size = n;                                 // the size of the stack
    s->top = -1;                                 // initialise top to -1
    s->A = (int *)malloc(sizeof(int) * s->size); // pointer to integer array
    return;
}

void push(Stack *s, int k) // add element to stack
{
    if (isStackFull(*s))
        return;         // return if stack is full don't add
    s->A[++s->top] = k; // increment the top element and then assign k element to top element of array
    return;
}

int pop(Stack *s) // return the topmost element last added
{
    if (isStackEmpty(*s))
        return INT_MAX; // if stack is empty do not pop

    int x = s->A[s->top]; // assign x to the top element of stack
    s->top--;             // decrement the top
    return x;             // return the top
}

int isStackFull(Stack s)
{
    return s.top == s.size - 1; // if top is equal to size of stack
}

int isStackEmpty(Stack s)
{
    return s.top == -1; // if top is equal to -1
}

int peek(Stack s)
{
    return s.A[s.top]; // return the topmost element
}

/*int main()
{
    Stack s;
    initStack(&s, 3); // pass size

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("\n");

    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    int d = pop(&s);
    if (d == INT_MAX)
        printf("Stack is Empty");
    else
        printf("Stack is empty");

    // printf("Topmost element is: %d\n", peek(s));

    // printf("%d\n", isStackEmpty(s));
    // printf("%d\n", isStackFull(s));
    return 0;
}*/