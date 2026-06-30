#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr-> size - 1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack *s, int data){
    if(isFull(s)){
        printf("Stack Overflow....\n");
    }else{
        s->top++;
        s->arr[s->top] = data;
        printf("Element %d pushed at index %d\n", data, s->top);
    }
}

void pop(struct stack * s){
    if(isEmpty(s)){
        printf("Stack Underflow..\n");
    }else{
        int val = s->arr[s->top];
        printf("Element %d at index %d removed\n",val, s->top); 
        s->top--;
    }
}

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s,10);
    push(s,20);
    pop(s);
    push(s,200);
    pop(s);
    return 0;
}