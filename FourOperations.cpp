#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

struct node{
	//general data
	char name[20];
	int score;
	//init next pointer
	struct node *next;
};

struct node* CreateList(){
	struct node *head, *pnode1, *pnode2;
	//initialize pnode1
	pnode1 = (struct node *)malloc(sizeof(struct node));
	printf("Please input the first student score");
	scanf("%d", &pnode1->score);
	printf("Please input the first student score");
	scanf("%s", &pnode1->name);
	head = pnode1;

	//stipulate the amount of linked list
	int amount, int num = 0;
	printf("How many students do you want to input?");
	scanf("%d", &amount);

	//initialize pnode2
	while(num < amount){
		pnode2 = (struct node *)malloc(sizeof(struct node));
		printf("Please input the %d student score", num+2);
		scanf("%d", &pnode1->score);
		printf("Please input the %d student score", num+2);
		scanf("%s", &pnode1->name);	

		pnode1->next = pnode2;
		pnode1 = pnode2;
	}

	pnode2 ->next = NULL;
	
	return head;
}

struct node* InsertNode(struct node** phead, int index, int mark){
	if(index < 0) return 0;

	//��ʼ��Ѱ�һ��ƣ����õ�ǰ������ָ��ָ��1
	int currIndex = 1;
	struct node* currNode = *phead;

	//�ƶ��������ж�ָ���Ƿ�������Ƿ��ƶ�������������index
	while(currNode && index > currIndex){
		currNode = currNode ->next;
		currIndex++;
	}
	if(index > 0 && currNode ==0) return 0;

	//�Ѿ��ҵ���Ҫ����newNode��λ��
	struct node* newNode;

	newNode = (struct node*)malloc(sizeof(struct node));
	strcpy(newNode->name, "Billy");
	newNode->score = mark;

	//��������������1. ����ͷ����index = 0���� 2. �����м�

	if(index == 0){//Ҳ����˵����Ҫ��List��ͷ������һ��node
		
		newNode->next = *phead;//Ҫ��newNode��ɵ�phead����

		*phead = newNode;//update phead
	
	}else{
		//��newNode��predecessor��next(new��successor)����newNode
		newNode->next = currNode->next;
		//��newNode��predecessor��newNode����
		currNode->next = newNode;
	}
	return newNode;
}

int main(){

	struct node *test, *newNode;

	test = CreateList();

	system("pause");

	return 0;
}