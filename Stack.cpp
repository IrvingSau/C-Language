#include"stack.h"
#include<stdio.h>
#include<stdlib.h>



bool CreateStack(Stack* stack, int size){
	//Handle exception
	if(size <= 0){
		return false;
	}

	//Create a double type pointer which points to a array(store the element)
	stack->values = (double*)malloc(sizeof(double)*size);

	stack->top = -1;//Now the stack is empty, and the next element's index is 0

	stack->maxTop = size - 1;//we must prepare a space for the pop and push, otherwise stack will overflow

	return true;
}

bool IsFULL(Stack* stack){
	//Judge if it is the top in the stack, if it is, that return true
	if(stack->top == stack->maxTop)
		return true;
	else
		return false;
}

bool IsEmpty(Stack* stack){
	//Judge if the top is empty, if it is, that return true
	if(stack->top == -1)
		return true;
	else
		return false;
}

bool Push(Stack* stack, double x){
	//Handle exception
	if(IsFULL(stack))
		return false;
	//we add 1 to the index of top
	stack->top++;
	//then we use top index to move the pointer
	stack->values[stack->top] = x;
	return true;
}

bool Pop(Stack* stack, double* x){
	//Handle exception
	if(IsFULL(stack))
		return false;
	//we store the value we pop to x
	*x = stack->values[stack->top];
	//then we reduce the index of top and then we can change the top
	stack->top--;

	return true;
}

bool Top(Stack* stack, double*x){
	//Handle exception
	if(IsEmpty(stack))
		return false;
	*x = stack->values[stack->top];
	return true;
}

void DisplayStack(Stack* stack){
	//Use for loop to output
	for(int i = stack->top; i > -1; i--)
		printf("%f\n", stack->values[i]);
}

void DestroyStack(Stack* stack){
	//free the pointer values, then we can destory the whole stack
	free(stack->values);
}
