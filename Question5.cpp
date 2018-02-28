#include<stdio.h>

void array_abs(float a[]){
	for(int i = 0; i < 5; i++){
		if(a[i] < 0)
			a[i] = a[i] * -1;
	}
}

int main(){

	float a[5];

	for(int i = 0; i < 5; i++){
		scanf("%f", &a[i]);
	}

	array_abs(a);

	for(int i = 0; i < 5; i++){
		printf("%f ", a[i]);
	}

	return 0;
}