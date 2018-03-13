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

	stack->top = -1;//����ջΪ��ջ����һ�������Ԫ��Ϊ��0��

	stack->maxTop = size - 1;//����Ԥ����һ���ռ�����pop��push����������ջ�������ʵ�ִ���

	return true;
}

bool IsFULL(Stack* stack){
	if(stack->top == stack->maxTop)
		return true;
	else
		return false;
}

bool IsEmpty(Stack* stack){
	if(stack->top == -1)
		return true;
	else
		return false;
}

bool Push(Stack* stack, double x){
	if(IsFULL(stack))
		return false;

	stack->top++;
	stack->values[stack->top] = x;
	return true;
}

bool Pop(Stack* stack, double* x){
	if(IsFULL(stack))
		return false;

	*x = stack->values[stack->top];
	stack->top--;

	return true;
}

bool Top(Stack* stack, double*x){
	if(IsEmpty(stack))
		return false;
	*x = stack->values[stack->top];
	return true;
}

void DisplayStack(Stack* stack){
	for(int i = stack->top; i > -1; i--)
		printf("%f\n", stack->values[i]);
}

void DestroyStack(Stack* stack){
	free(stack->values);
}

int main(){

	Stack stack;
	
	double val;

	CreateStack(&stack, 5);
	
	Push(&stack, 5);
	Push(&stack, 6.5);
	Push(&stack, -3);
	Push(&stack, -8);
	
	DisplayStack(&stack);
	
	if(Top(&stack, &val))
		printf("Top: %g\n", val);
	
	Pop(&stack, &val);
	
	if(Top(&stack, &val))
		printf("Top: %g\n", val);
	
	while(!IsEmpty(&stack))
		Pop(&stack, &val);
	
	DisplayStack(&stack);
	
	DestroyStack(&stack);
	

	return 0;
}