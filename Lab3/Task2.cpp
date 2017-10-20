#include<stdio.h>
int main()
{
	int num1, num2;

	printf("Please input two numbers:");
	scanf("%d%d", &num1, &num2);
	
	num1>num2?printf("The %d is the smaller one\n", num2):printf("The %d is the smaller one\n", num1);
	
	return 0;
}