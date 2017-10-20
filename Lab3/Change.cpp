#include<stdio.h>

int main()
{
	int a , b, c;

	printf("Please input an double-digit number:");
	scanf("%d", &a);

	c = a*1.0 / 10;

	b = a % 10;

	printf("The change is %d%d\n", b, c);

	return 0;
}