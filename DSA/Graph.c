#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Queue.c"
#include "LinkedStack.c"

#define Max 10

struct graph
{
    int a[Max][Max]; // 10*10 matrix
    int n;           // number of nodes in graoh
};
typedef struct graph graph;

struct edge
{
    int s, d, w;
};
typedef struct edge edge;

void initFromFile(graph *g, char *graphFile);
void printGraph(graph *g);
void BFS(graph g, int s); // Breadth First Search;
void DFS(graph g, int x);

void initFromFile(graph *g, char *graphFile)
{
    int x;
    FILE *fp;
    int i, j;
    fp = fopen(graphFile, "r"); // open file in read mode

    if (fp == NULL) // if file is empty
    {
        printf("Unable to open file.\n");
        return;
    }

    fscanf(fp, "%d", &x); // read data from file
                          // first line
    g->n = x;             // vertices of graph
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x; j++)
            fscanf(fp, "%d", &(g->a[i][j])); // read input from file
    }
    return;
}

void printGraph(graph *g)
{
    int i, j;
    for (i = 0; i < g->n; i++)
    {
        for (j = 0; j < g->n; j++)
            printf("%d ", g->a[i][j]);
        printf("\n");
    }
    return;
}

void BFS(graph g, int s) // Breadth First Search
{
    Queue q; // enter the unvisited entries in a queue
    initQ(&q);
    int x, i;
    int *visited = (int *)malloc(sizeof(int) * g.n); // create an array to mark whether a number is visited or not
    for (i = 0; i < g.n; i++)
        visited[i] = 0;      // initially mark all entries as 0
    enQueue(&q, s);          // enquque start point  of graph
    visited[s] = 1;          // mark s as visited in array
    while (!isQueueEmpty(q)) // repeat until queue empty
    {
        x = deQueue(&q);
        printf("%d ", x);
        for (i = 0; i < g.n; i++)
        {
            if (g.a[x][i] != 0 && !visited[i])
            {                   // check if not visited and
                                // there is a edge from x to i
                enQueue(&q, i); // if yes then enqueue i
                visited[i] = 1; // and mark visited as 1
            }
        }
    }
    return;
}

void DFS(graph g, int x)
{
    SNode ls;
    int *visited = (int *)calloc(g.n, sizeof(int)); // initialise all elements with 0
    visited[x] = 1;                                 // mark as visited
    printf("%d ", x);
    PushLinkedStack(&ls, x);
    int n, i;
    while(!isLinkedStackEmpty(ls))
    {
        n = peekLinkedStack(ls); // find top of stack
        // find an adjacent unvisited vartex of n
        for ( i = 0; i < g.n; i++)          
        {
            if (g.a[n][i] && !visited[i])
            {
                visited[i] = 1;
                printf("%d ", i);
                PushLinkedStack(&ls, i);
                break;
            }
        }
        if (i == g.n)
        {
            PopLinkedStack(&ls);
        }
        
    }
    return;
}


int main()
{
    graph g1;
    initFromFile(&g1, "graphFile.txt");
    printGraph(&g1);
    printf("\n");
    BFS(g1, 2);
    printf("\n");
    DFS(g1, 0);
    return 0;
}