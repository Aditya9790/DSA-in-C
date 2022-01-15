#include <stdio.h>
void swap(int *xp, int *yp);
void selectionSort(int arr[], int n);
void printArray(int arr[], int size);

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx ;
    int len = 8;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
        printArray(arr, len);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return;
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {89 ,46 ,54 ,32 ,90 ,40 ,80, 50};
    int len = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, len);
    printf("Sorted array: \n");
    printArray(arr, len);
    return 0;
}