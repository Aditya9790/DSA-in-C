#include<stdio.h>
void printArray(int A[], int len);
void insertionSort(int A[], int len);


void insertionSort(int A[], int len)
{
    int x, j;
    for(int i=1; i < len; i++)
    {
        x = A[i];
        for(j=i-1; j>=0; j--)
        {
            if(A[j]>x)
                A[j+1] = A[j];
            else
                break;
        }
        A[j+1] = x;
    }
    return;
}
void printArray(int A[], int len)
{
    for(int i=0 ; i<len; i++)
        printf("%d ", A[i]);
}
int main()
{
    int A[] = {20,10,8,1,0};
    int len = sizeof(A)/sizeof(int); //length of array
    printf("Unsorted array is: ");
    printArray(A, len);
    insertionSort(A, len);
    printf("\nSorted array by Insertion Sort is: ");
    printArray(A, len);
    
    return 0;
}
