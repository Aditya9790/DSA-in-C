// First In First Out Data Structure
// FIFO Type

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue // Queue will have front and rear to keep track of
{                    // first and last element
    Node *front, *rear;
} Queue;

void initQ(Queue *q)
{
    //Initially point front and rear to NULL
    q->front = NULL;
    q->rear = NULL;
    return;
}

void enQueue(Queue *q, int k)
{
    Node *nn = (Node *)malloc(sizeof(Node)); // create a new node
    if (!nn)
        return;
    nn->data = k;    // Assign data to new node
    nn->next = NULL; // point new node.next to null

    if (q->rear == NULL) // is the queue empty
    {
       // printf("Queue Initialised....\n");
        q->rear = nn;
        q->front = nn;
        return;
    }
    // if queue is not empty then rear's next must point to new node
    // as rear is the last node in queue
    q->rear->next = nn;
    q->rear = nn; // rear always points to the last element
    return;
}

int deQueue(Queue *q)
{
    int x = INT_MAX;
    Node *p;

    if (q->front == NULL) // If queue is empty, return NULL.
        return -1;

    x = q->front->data;
    p = q->front; // directly cannot free q so assign it to another variable

    // If front becomes NULL, then change rear also as NULL
    if (q->front != NULL && q->front == q->rear) // if queue only has one element
    {
        q->front = NULL;
        q->front == NULL;
    }
    else
        q->front = p->next; // update the front and free current front
    free(p);

    return x;
}

int isQueueEmpty(Queue q)
{
        // printf("Queue Empty...");
        return q.front == NULL; // 1 if empty else 0
}

// Driver Program to test above functions
/*int main()
{
    Queue q;
    initQ(&q);
    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    // enQueue(&q, 40);
    // enQueue(&q, 50);
    printf("%d\n", deQueue(&q));
    printf("%d\n", deQueue(&q));
    printf("%d\n", deQueue(&q));
    printf("%d\n", isQueueEmpty(q));
    return 0;
}*/