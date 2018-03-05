#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//初始化结点
typedef struct node{

	//常规数据
	int score;
	char name[20];
	
	//next指针
	struct node *next;

}node;

int main(){

	node *pnode, *head;//Create two node type pointer

	pnode = (node *)malloc(sizeof(node));//先用pnode作为媒介，使内存分配位置给pnode

	strcpy(pnode -> name, "John");//为pnode赋值
	pnode -> score = 100;

	head = pnode;//将第一次输入的结点作为head

	pnode = (node *)malloc(sizeof(node));//pnode再次作为媒介分配内存

	strcpy(pnode -> name, "Tony");//为pnode赋值
	pnode -> score = 90;

	head -> next = pnode;//使头的next指针指向pnode
	pnode ->next = NULL;//使末尾的next指针指向NULL

	return 0;
}