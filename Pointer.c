#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("X = %d, Y = %d\n", *a, *b);
    return;
}

int main()
{
    // stack s1, s2;
    // initStack();

    // int arr[] = {10, 20, 30, 40, 50, 60};

    // int *ptr1 = arr;

    // int *ptr2 = arr + 5;

    // int n = ptr1 - ptr2;
    //printf("%d", n);
    int x = 10, y = 20;

    swap(&x, &y);
    printf("X = %d, Y = %d", x, y);

    return 0;
}