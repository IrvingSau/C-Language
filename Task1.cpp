#include <stdio.h>

long int factR(int n){
	//base, if n = 0, return 0, if n = 1, return 1
	if(n <= 1){
	return n;
	}else{
		return n * factR(n - 1);
	}
}

int main(){
	//simple IO
	int n, result;
	scanf("%d", &n);
	result = factR(n);
	printf("%d\n", result);
	return 0;
}