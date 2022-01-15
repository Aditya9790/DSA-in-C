#include<stdio.h>
void message();
int main()
{
	printf("Hi I am result of main function.\n");
	message();
	return 0;
}
void message()
{
	printf("I am result of void message.\n");
}
