#include <stdio.h>

// Traversal
void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}

// Insertion
int indInsertion(int arr[], int *size, int element, int capacity, int index){
    if(*size >= capacity){
        return -1;
    }
    for(int i = *size - 1; i >= index; i--){
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    (*size)++;
    return 1;
}



int main(){
    int arr[100] = {10,20,40,50,60};
    int size = 5, element = 30, index = 2;
    
    display(arr, size);
    
    int result = indInsertion(arr, &size, element, 100, index);
    if(result == 1){
        printf("\nInsertion Succesful\n");
        display(arr, size);
    }else{
        printf("\nInsertion Failed");
    }
    return 0;
}