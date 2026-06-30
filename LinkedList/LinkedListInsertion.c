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

// Function for inserting node at the beginning - requires head node, and data to insert
struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// Function for adding node in between - requires head node, index, and data
struct Node *insertAtIndex(struct Node *head, int index, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    
    int i = 0;
    
    while (i != index - 1)
    {
        p = p -> next;
        i++;
    }
    
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Function for adding node at the end - requires head node, and data
struct Node *insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr -> data = data;
    
    while(p -> next != NULL){
        p = p -> next;
    }

    p -> next = ptr;
    ptr -> next = NULL;
    return head;
}

// Function for adding a node after a specific node - requires head node, specific node, and data
struct Node *insertAfterNode(struct Node *head, struct Node * prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    
    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;

    return head;
}


int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    
    // Allocating dynamic memory to nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Linking nodes 
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    head = insertAfterNode(head,second, 25);
    linkedListTraversal(head);

    return 0;
}