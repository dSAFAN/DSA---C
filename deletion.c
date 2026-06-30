#include <stdio.h>

// Traversal
void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}

// Deletion
int indDeletion(int arr[], int *size, int index){

    for(int i = index; i < *size-1; i++){
        arr[i] = arr[i + 1];   
    }
    (*size)--;
}

int main(){
    int arr[100] = {10,20,40,50,60};
    int size = 5, index = 2;
    display(arr, size);
    indDeletion(arr, &size, index);
    printf("\n");
    display(arr, size);
    printf("\n Size : %d", size);
    return 0;
}