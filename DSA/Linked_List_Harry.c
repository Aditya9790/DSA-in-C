#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head; //gobal variable, can be accessed anywhere

void Insert(int x);
{
    struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = NULL;

}

int main()
{
    int len, elem;
    head = NULL; // lempty list
    printf("Enter length of list: ");
    scanf("%d\n", &len);

    for(int i=0; i<len; i++)
    {
        printf("Enter the %d element: ", i);
        scanf("%d\n", &elem);
        Insert(elem);
        Print();
    }
}














































































































































































// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;          // data to store in node
//     struct Node *next; // pointer to next node address
// };

// struct Node *head; // pointer to struct node

// void InsertNode(int elem)
// {
//     struct Node *new_node; // node that we are going to create

//     // since the new_node is a void pointer so we will typecast it to struct
//     new_node = (struct Node *)malloc(sizeof(struct Node));










// //     // takes new node(nn) as a parameter 
// //     // and tht element to be added i.e. elem
// //     temp_node = (struct Node* )malloc(sizeof(struct Node));

// //     temp_node -> data = elem;
// //     if (first_node==0) // If the list is empty
// //         first_node = temp_node;
// //     else
// //         head_node -> next = temp_node;
    

// //     temp_node ->next = NULL;
// // }



// void LLTraverse(struct Node *ptr)
// {
//     //ptr is a pointer that points to head node
//     //and keep track of every element
//     printf("[ ");
//     while (ptr != NULL)
//     {
//         printf("%d ", ptr->data);
//         ptr = ptr->next;
//     }
//     printf(" ]");
// }

// int main()
// {
//     struct Node *head; // initialise the start of the Linked list
//     struct Node *second;
//     struct Node *third;
//     struct Node *fourth;
//     struct Node *fifth;

//     // head is not of the type struct rather it is a
//     // pointer to struct data type
//     // value of the struct elements can be assigned by -> operator
//     // (pointer_name) -> variable_name = variable_value

//     // Allocate memory for nodes in linked list in Heap
//     head = (struct Node *)malloc(sizeof(struct Node));
//     second = (struct Node *)malloc(sizeof(struct Node));
//     third = (struct Node *)malloc(sizeof(struct Node));
//     fourth = (struct Node *)malloc(sizeof(struct Node));
//     fifth = (struct Node *)malloc(sizeof(struct Node));

//     // Link first and second node
//     head->data = 7;
//     head->next = second;

//     // Link second and third node
//     second->data = 10;
//     second->next = third;

//     // Link thirdt and fourth node
//     third->data = 12;
//     third->next = fourth;

//     // Link fourth anf fifth node
//     fourth->data = 0;
//     fourth->next = fifth;

//     // Link fifth to NULL
//     fifth->data = 20;
//     fifth->next = NULL;

//     LLTraverse(head);
//     return 0;
// }
