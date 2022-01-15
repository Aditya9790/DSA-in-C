#include<stdio.h>
#include<stdlib.h>

// Merge sort merges two sorted array recursively
void MergeSort(int A[], int low, int high);
void printArray(int A[], int len);
void Merge(int A[], int mid, int low, int high);


void Merge(int A[], int mid, int low, int high)
{
    int i, j, k;
    int B[high+1];
    i=low;
    j=mid+1;
    k=low; // keep track of new list B

    while(i<=mid && j<=high) // go through the individual parts in sorted list
    {
        if(A[i] < A[j]){
            B[k] = A[i];
            i++;
        }
        else{
            B[k] = A[j];
            j++;
        }
        k++;
    }

    while(i<=mid) // copy the remaining elements in a temp array(if remaining)
    {
        B[k] = A[i];
        k++; 
        i++;
    }

    while(j<=high) // copy the remaining elements in a temp array(if remaining)
    {
        B[k] = A[j];
        k++;
        j++;
    }

    for(i=low; i<=high; i++) // copy back elements of A from B
        A[i] = B[i];
}


void MergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low+high)/2 ;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, mid, low, high);
    }
}

// Array printing function
void printArray(int A[], int len)
{
    for(int i=0 ; i<len; i++)
        printf("%d ", A[i]);
    return;
}

int main()
{
    int A[] = {20,10,8,1,0};
    int len = sizeof(A)/sizeof(int); //length of array
    printf("\nUnsorted array is: ");
    printArray(A, len);

    MergeSort(A, 0, len-1);
    
    printf("\nSorted array by Merge Sort Sort is: ");
    printArray(A, len);
    
    return 0;
}
