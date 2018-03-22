#include<stdio.h>
typedef struct stack{
	char* values;
	int maxTop;
	int topIndex;
}Stack;

//Creat a stack
bool CreatStack(Stack* stack, int size);

//Pop the top out of stack
char pop(Stack* stack);

//Push element into stack
bool push(Stack* stack, char input);

//Judge if the stack is empty
bool isEmpty(Stack* stack);

//Judge if the stack is full
bool isFull(Stack* stack);

//Judge the sign we input if it is opening or closing 
bool isOpening(char sign);

//Judge if the opening sign is matched with closing sign
bool isMatching(char opening, char closing);

//Judge if the string is ValidBrackets
bool ValidBrackets(char* str);