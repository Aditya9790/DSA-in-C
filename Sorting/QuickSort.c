#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int len);
void QuickSort(int A[], int low, int high);
int partition(int A[], int low, int high);

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (A[i] <= pivot)
        { // to get element greater than pivot
            i++;
        }

        while (A[j] > pivot)
        { // to get element lesser than pivot
            j--;
        }

        if (i < j)
        { // if i < j swap A[i] and A[j]
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);    

    // Swap A[low] and A[j]
    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j; // Index of element that is finally settlled
}

void QuickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        printArray(A, 9);printf("\n");
        QuickSort(A, low, partitionIndex - 1);  // Sort left subarray
        QuickSort(A, partitionIndex + 1, high); // Sort right subarray
    }
}

void printArray(int A[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", A[i]);
}

int main()
{
    int A[] = {20, 10, 8, 1, 0, 98, 32, -2, -20};
    int len = sizeof(A) / sizeof(int); //length of array
    printf("\nUnsorted array is: ");
    printArray(A, len);

    printf("\n");
    
    QuickSort(A, 0, len - 1); // Calling the function

    printf("\nSorted array by Quick Sort is: ");
    printArray(A, len);
    return 0;
}
