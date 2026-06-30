#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverseCircularLLC(struct Node * head){
    struct Node *p = head;
    do
    {
        printf("Data : %d\n", p -> data);
        p = p -> next;

    } while (p != head);
    
}

struct Node * InsertAtBeginning(struct Node * head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    
    struct Node *p = head -> next;
    while (p -> next != head){
        p = p -> next;
    }

    p -> next = ptr;
    ptr -> next = head;
    head = ptr;
    return head;
    

}

int main(){
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
    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = head;

    head = InsertAtBeginning(head, 0);
    head = InsertAtBeginning(head, 1);
    traverseCircularLLC(head);
    return 0;
}