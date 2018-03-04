#include<stdio.h>
#include<Windows.h>

//use Euclidean algorithm to find gcd
int GCD(int first, int second){
	if(first % second == 0)//if a / b has no remainder, b is the gcd
		return second;
	else if(first % second != 0)//else if a / b has remainder r1, then use b / r1 and the r2 if is 0, r1 is the gcd
		GCD(second , first % second);
}

int main(){
	//Simple IO
	int first, second;

	scanf("%d %d", &first, &second);

	int gcd = GCD(first, second);

	printf("The gcd is: %d\n", gcd);

	system("pause");

	return 0;
}