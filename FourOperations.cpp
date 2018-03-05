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

	//初始化寻找机制，设置当前索引与指针指向1
	int currIndex = 1;
	struct node* currNode = *phead;

	//移动检索，判断指针是否存在且是否移动超出了索引的index
	while(currNode && index > currIndex){
		currNode = currNode ->next;
		currIndex++;
	}
	if(index > 0 && currNode ==0) return 0;

	//已经找到了要插入newNode的位置
	struct node* newNode;

	newNode = (struct node*)malloc(sizeof(struct node));
	strcpy(newNode->name, "Billy");
	newNode->score = mark;

	//插入分两种情况，1. 插入头部（index = 0）， 2. 插入中间

	if(index == 0){//也就是说我们要在List的头部插入一个node
		
		newNode->next = *phead;//要将newNode与旧的phead链接

		*phead = newNode;//update phead
	
	}else{
		//将newNode的predecessor的next(new的successor)赋给newNode
		newNode->next = currNode->next;
		//将newNode的predecessor与newNode链接
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