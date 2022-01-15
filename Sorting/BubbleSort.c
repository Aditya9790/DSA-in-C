// Optimized implementation of Bubble sort
#include <stdio.h>
void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
  
// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   int flag = 0;
   for (i = 0; i < n-1; i++)
   {
     flag = 0;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           flag = 1;
        }
     }
  
     // IF no two elements were swapped by inner loop, then break
     if (flag == 0)
        break;
   }
}
  
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
  
// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(int);
    bubbleSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
