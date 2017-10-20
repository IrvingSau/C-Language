#include<stdio.h>

int main()
{
	int n;
	int flag;// define the bool 0 and 1;

	printf("Please input an integer n:");
	scanf("%d", &n);

	if(n<0){
		n = -n;
		flag = 1;
	}

	n = n + n;

	printf("n is equal to %d now\n", n);

	return 0;
}