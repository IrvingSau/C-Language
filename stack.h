typedef struct{
	
	double* values;//ָ�����ջ��Ԫ�ص�����

	int top;//ջ����˵�index
	
	int maxTop;//ջ�����ߴ�
}Stack;

bool CreateStack(Stack* stack, int size);


bool IsFULL(Stack* stack);


bool IsEmpty(Stack* stack);

bool Top(Stack* stack, double* x);

bool Push(Stack* stack, double x);

bool Pop(Stack* stack, double* x);

void DisplayStack(Stack* stack);

void DestroyStack(Stack* stack);