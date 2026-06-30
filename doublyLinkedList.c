#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};


void traverse(struct Node *head, struct Node *tail, bool forward)
{
    struct Node *curr = forward ? head : tail;

    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = forward ? curr->next : curr->prev;
    }
    printf("\n");
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *tail;

    // Allocating dynamic memory to nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    tail = (struct Node *)malloc(sizeof(struct Node));

    // Linking nodes
    head->data = 4;
    head->next = second;
    head->prev = NULL;

    second->data = 3;
    second->next = third;
    second->prev = head;

    third->data = 6;
    third->next = tail;
    third->prev = second;

    tail->data = 1;
    tail->next = NULL;
    tail->prev = third;

    traverse(head, tail, true);
    traverse(head, tail, false);

    return 0;
}