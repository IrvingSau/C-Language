typedef struct{
	
	double* values;//指向存有栈中元素的数组

	int top;//栈的最顶端的index
	
	int maxTop;//栈的最大尺寸
}Stack;

bool CreateStack(Stack* stack, int size);


bool IsFULL(Stack* stack);


bool IsEmpty(Stack* stack);

bool Top(Stack* stack, double* x);

bool Push(Stack* stack, double x);

bool Pop(Stack* stack, double* x);

void DisplayStack(Stack* stack);

void DestroyStack(Stack* stack);