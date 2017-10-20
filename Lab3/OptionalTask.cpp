#include<stdio.h>

int main()
{
	int n;

	printf("Please input an integer n:");
	scanf("%d", &n);

	if(n < 0 && n > -10){
		n = n;
	}else{
		n = -n;
	}

	n = n + n;

	printf("now n is equal to %d.\n", n);

	return 0;
}
