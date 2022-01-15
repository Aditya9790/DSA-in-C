#include<stdio.h>
void printArray(int A[], int len);
int BinarySearch(int A[], int first, int last, int key);

// BinarySearch Function
int BinarySearch(int A[], int first, int last, int key)
{
   int len = sizeof(A[0])/sizeof(int);

   if(first > last){
       printf("Not found\n");
       return 0;
   }

   int mid = (first + last)/2;

    if (A[mid] == key){
        printf("Found\n");
        return 1;
    }
    if (key > A[mid])
        return BinarySearch(A, mid+1, last, key);
    else
        return BinarySearch(A, first, mid-1, key);

}

// Array printing function
void printArray(int A[], int len)
{
    for(int i=0 ; i<len; i++)
        printf("%d ", A[i]);
}

int main()
{
    int A[] = {24, 45, 67, 89, 90,130, 145, 167, 180, 200};
    int key;
    printf("Array is: ");
    int len = sizeof(A)/sizeof(int);
    printArray(A, len);
    printf("\nEnter element to search: ");
    scanf("%d", &key);
    
    BinarySearch(A, 0, len-1, key);
    
    return 0;
}