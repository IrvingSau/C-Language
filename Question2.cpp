#include<stdio.h>

float abs(float a){
	if(a > 0)
		a = a;
	if(a < 0)
		a = a * -1;
	return a;
}

int main(){
	float input, result;

	printf("Enter a floating-point number: ");
	scanf("%f", &input);
	
	result = abs(input);

	printf("The absolute value of %f is %f", input, result);

	return 0;
}