# include<stdio.h>
int factorial(int n);
int factorial(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return (n * factorial(n-1));
    }
}

int main()
{
    int n, ans;
    printf("Enter the number: ");
    scanf("%d", &n);
    ans = factorial(n);
    printf("Factorial of %d is: %d\n", n, ans);
    return 0;
}