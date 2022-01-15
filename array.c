# include<stdio.h>
/* Single dimentional array
int main()
{
    int j=0, marks[4];
    for (int i = 1; i <=4; i++)
    {
        printf("Enter the %d th element: ", i);
        scanf("%d", &marks[i]);
    }
    printf("\n");
    for (int j = 1; j<=4; j++)
    {
        printf("The %d th element is: %d\n", j, marks[j]);
    }
    return 0;
}*/

// 2-D array
int main()
{
    int two_d_array[2][4];
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<4; j++)
        {
            printf("Enter the element at (%d, %d) position: ", i, j);
            scanf("%d", &two_d_array[i][j]);
        }
    }
    printf("\n");
    for (int k=0; k<2; k++)
    {
        for (int l=0; l<4; l++)
        {
            printf("%d ",two_d_array[k][l]);
        }
        printf("\n");
    }
    return 0;
}