#include<stdio.h>
#include<stdlib.h>

void Reverse_Array(int A[], int len);
void printArray(int A[], int len);

void Reverse_Array(int A[], int len)
{
	for (int i=0; i < len/2; i++){
        int temp = A[i];
		A[i] = A[len-1-i];
		A[len-1-i] = temp;
    }
}

void printArray(int A[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", A[i]);
}

int main()
{
	int A[] = {20, 0, -10, 6, 3, 200, 100, 2};
	int len = sizeof(A)/sizeof(int);
	//Printing A
    printf("Origional array is: ");
	printArray(A, len);

	// Reverse array function
	Reverse_Array(A, len);

	// Reprinting the reversed array
	printf("\nReverse array is : ");
	printArray(A, len);
	return 0;
}