#include<malloc.h>
#include<stdio.h>

int main(){
	int amount;
	float result = 1;

	printf("How many floating point numbers do you want to multiply together: ");
	scanf("%d", &amount);

	float *p = (float *)malloc(amount * sizeof(float));
	if(p != NULL){
		for (int i = 0; i < amount; i++){
			printf("Enter a floating-point number: ");
			scanf("%f", p);
			result = result * *p;
			p++;
		}

		printf("The product is %f", result);

		free(p);
	}else{
		printf("malloc is NULL!\n");
	}

	return 0;
}