#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next; // self referencing
};

void push(int value, struct node **head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = NULL;

    if (*head == NULL) // If List is empty
    {
        *head = ptr;
        return;
    }
    struct node *curr;
    curr = *head; // create a current node pointing to head node

    while (curr->next != NULL) // iterate until we reach to the end of the list and then append the element
        curr = curr->next;

    curr->next = ptr;
    return;
}

static void reverse(struct node **head_ref)
{
    struct node *prev = NULL;
    struct node *current = *head_ref;
    struct node *next = NULL;
    while (current != NULL)
    {

        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

void printlist(struct node **head)
{
    if (*head == NULL) // If list is empty
    {
        printf("NULL \n");
        return;
    }

    // initialise a pointer (curr) to a node to keep track of current value
    struct node *curr;
    curr = *head; // make current node to head node

    while (curr != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");

    return;
}

void delete (int key, struct node **head)
{
    if (*head == NULL) // If list is empty
        return;

    if ((*head)->data == key) // If the element we want to delete is first element
    {
        (*head) = (*head)->next;
        return;
    }
    struct node *curr = *head; // initialise current element as head
    struct node *prev = NULL;  // assign a pointer to keep track of previous value

    while (curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;

    return;
}

void search(int key, struct node **head)
{
    struct node *curr = *head;
    while (curr->data != key && curr->next != NULL)
        curr = curr->next;

    if (curr->data == key)
        printf(" %d is present\n", key);
    else
        printf("%d id not present\n", key);
}

int count(struct node **head)
{
    struct node *curr;
    curr = *head;
    int count = 0;

    while (curr != NULL)
    {
        count += 1;
        curr = curr->next;
    }
    return count;
}

int main()
{

    struct node *head = NULL;
    push(5, &head);
    push(4, &head);
    push(3, &head);
    push(2, &head);
    search(5, &head);
    printlist(&head);
    reverse(&head);

    printf("Elements before deletion: %d\n", count(&head));

    delete (2, &head);
    printlist(&head);
    printf("Elements after deletion: %d\n", count(&head));
    return 0;
}