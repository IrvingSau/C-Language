#include<stdio.h>

int main(void){
	int first, second;

	printf("Enter the first integer: ");
	scanf("%d", &first);

	printf("Enter the second integer: ");
	scanf("%d", &second);

	if(first >= 0 && second >= 0){
	printf("The integer 3 and 0 are both positive\n");
	}else{
	printf("The integer 3 and 0 are not both positive\n");
	}

	return 0;
}
