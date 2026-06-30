#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function for traversal - requires head node
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function for deleting the first node - requires head node
struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Function for a node in between - requires head node, and index
struct Node *deleteNodeInBetween(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = p->next;

    int i = 0;
    while(i < index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    free(q);
    return head;
}

// Function for deleting the last node - requires head node
struct Node *deleteLastNode(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = p->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}
// Function for deleting the node with a given value - requires head node, and value
struct Node *deleteAfterNode(struct Node *head, int value)
{
    struct Node *p =head;
    struct Node *q = p -> next;
    
    while(q->data != value && q->next != NULL){
        p = p -> next;
        q = q -> next;
    }

    if(q->data == value){
        p -> next = q -> next;
        free(q);
    }else
    {
        printf("Node with the value %d not found in the linked list\n", value); 
    }
    
    return head;
}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocating dynamic memory to nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Linking nodes
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    head = deleteAfterNode(head,99);
    linkedListTraversal(head);

    return 0;
}
