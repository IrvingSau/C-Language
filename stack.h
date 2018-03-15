typedef struct{
	
	double* values;//ָ�����ջ��Ԫ�ص�����

	int top;//ջ����˵�index
	
	int maxTop;//ջ�����ߴ�
}Stack;

bool CreateStack(Stack* stack, int size);
//Creates an empty stack whose capacity is size

bool IsFULL(Stack* stack);
//Returns true if the stack is empty and false otherwise

bool IsEmpty(Stack* stack);
//Returns true if the stack is full and false otherwise

bool Top(Stack* stack, double* x);
//�C Returns true if the operation is successful and false otherwise
// - Passes the value of the top element to x

bool Push(Stack* stack, double x);
//�C Add a new element with value x to the top of the stack
//�C Returns true if the operation is successful and false otherwise
bool Pop(Stack* stack, double* x);
//Remove an element from the top of the stack
//�C Returns true if the operation is successful and false otherwise
//�C Passes the value of the top element to x

void DisplayStack(Stack* stack);
// show the stack we create and operate

void DestroyStack(Stack* stack);
// Frees the memory occupied by stack