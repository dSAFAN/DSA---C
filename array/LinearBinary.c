#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Linear Search to find target index for specific element
int LinearSearch(int arr[], int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// Binary search - Condition : Sorted array
int BinarySearch(int arr[], int target, int size)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    // Start Searching
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // End Searching

    return -1;
}

int main()
{

    int arr[] = {1, 4, 5, 2, 6, 7, 22, 4, 677, 432, 23, 98};
    int sarr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(sarr) / sizeof(int);
    int target = 7;

    // -------------- Linear Search -------------

    // int searchIndex = LinearSearch(arr, target,size);
    // printf("Array : \n");
    // display(arr,size);

    // printf("\n\n");
    // printf("Searching index for element %d\n", target);
    // if(searchIndex == -1){
    //     printf("Element not found....");
    // }else{
    //     printf("The element %d was found at index: %d",target, searchIndex);
    // }

    // -------------- Binary Search -------------

    int searchIndex = BinarySearch(sarr, target, size);
    if (searchIndex == -1)
    {
        printf("Element not found..");
    }
    else
    {
        printf("Element found at index %d", searchIndex);
    }

    return 0;
}