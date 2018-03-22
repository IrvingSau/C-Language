#include"ValidBrackets.h"
#include<stdio.h>
#include<stdlib.h>

bool CreatStack(Stack* stack, int size){
	if(size < 0) return false;

	//Initialize the top index
	stack->topIndex = -1;

	//create a 10 size of memory space for values
	stack->values = (char*)malloc(sizeof(char) * size);

	//Max of topIndex is size - 1
	stack->maxTop = size - 1;
}

//Judge if the stack is empty
bool isEmpty(Stack* stack){
	if(stack->topIndex == -1)
		return true;
	else
		return false;
}

//Judge if the stack is full
bool isFull(Stack* stack){
	if(stack->topIndex == stack->maxTop)
		return true;
	else
		return false;
}

//push the element into stack
bool push(Stack* stack, char input){
	if(isFull(stack))
		return false;
	else{
		stack->topIndex++;
		stack->values[stack->topIndex] = input;
		return true;
	}
}

//pop the top out of stack
char pop(Stack* stack){
	if(isEmpty(stack))
		return NULL;
	else{
		char output = stack->values[stack->topIndex];
		stack->topIndex--;
		return output;
	}
}

//Judge if the sign is opening or closing sign
bool isOpening(char sign){
	if(sign == '(' || sign == '[' || sign == '{')
		return true;
	else if(sign == ')' || sign == ']' || sign == '}')
		return false;
}

//Juege if the opening sign is matched with closing sign
bool isMatching(char opening, char closing){
	// Judgement for ()
	if(opening == '('){
		if(closing == ')')
			return true;
		else
			return false;
	}
	// Judgement for []
	else if(opening == '['){
		if(closing == ']')
			return true;
		else
			return false;
	}
	// Judgement for {}
	else if(opening == '{'){
		if(closing == '}')
			return true;
		else
			return false;
	}
}

bool ValidBrackets(char* str){
	if(str == NULL) return false;

	Stack stack;
	CreatStack(&stack, 10);

	for(int i = 0; i < 10; i++){
		//Judge if the input is legal or not
		if(str[i] == '(' ||str[i] == ')' ||str[i] == '{' ||str[i] == '}' ||str[i] == '[' ||str[i] == ']'){
			// if the character is opening character, push into stack
			if(isOpening(str[i])){
				push(&stack, str[i]);
			}
			//if the character is closing character
			else if(!isOpening(str[i])){
				//if the stack is empty, that return false
				if(isEmpty(&stack)){
					return false;
				}else{
					//if the stack is not empty, then we pop out the element and compare
					if(isMatching(pop(&stack), str[i]))
						return true;
					else
						return false;
				}
			}
		}else
			return false;
		if(str[i] == '\0')
			break;
	}
}

int main(){

	// initialize the size of string is 50
	char str[50];

	printf("Please input the String: ");

	// input the string
	scanf("%s", str);

	// according to the return value of ValidBrackets(), decide the output
	bool flag = ValidBrackets(str);
	if(flag)
		printf("true");
	else
		printf("false");
	return 0;
}


