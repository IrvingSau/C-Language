#include<stdio.h>
int main(void)
{
	int percentage, x;
	char ch1, ch2;

	scanf("%d%c%c%d", &percentage, &ch1, &ch2, &x);
	printf("%d%% %c%c %d is %f\n", percentage, ch1, ch2, x, x * 1.0 * percentage / 100);
	return 0;
}
	//1. 25of60: 25% of 60 is 15.000000
	//2. 25 of60:  25% o -858993460 is -214748365.000000
	//3. 25 of 60: 25% o -858993460 is -214748365.000000
