#include<stdio.h>
int main(void)
{
	int num1, num2;

	printf("please input two integers:\n");
	scanf("%d%d", &num1, &num2);

	printf("%f/%f=%f", num1*1.0, num2*1.0, num1*1.0/num2*1.0);//use *1.0 to transfer the integer to float.

	return 0;
}