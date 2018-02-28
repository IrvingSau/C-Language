#include<stdio.h>

int main(){
	int start, end;
	
	printf("Enter the start integer: ");
	scanf("%d", &start);
	printf("Enter the end integer: ");
	scanf("%d", &end);
	
	for(int i = start; i <= end; i++){
	printf("%d ", i);
	}

	return 0;
}

//yingranma@uic.edu.hk