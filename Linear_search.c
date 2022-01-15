# include<stdio.h>
int main()
{
    int A[] = {20, 0, -10, 6, 3, 200}, n, flag = 0;
    int len = sizeof(A)/sizeof(int); // length of array
    
    printf("Enter the element to find: ");
    scanf("%d", &n);

    for (int i=0; i<len; i++)
    {
        if (A[i] == n)
        {
            printf("%d found at %d th position.", n, i);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("Not found");
    return 0;
}