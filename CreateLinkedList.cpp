#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��ʼ�����
typedef struct node{

	//��������
	int score;
	char name[20];
	
	//nextָ��
	struct node *next;

}node;

int main(){

	node *pnode, *head;//Create two node type pointer

	pnode = (node *)malloc(sizeof(node));//����pnode��Ϊý�飬ʹ�ڴ����λ�ø�pnode

	strcpy(pnode -> name, "John");//Ϊpnode��ֵ
	pnode -> score = 100;

	head = pnode;//����һ������Ľ����Ϊhead

	pnode = (node *)malloc(sizeof(node));//pnode�ٴ���Ϊý������ڴ�

	strcpy(pnode -> name, "Tony");//Ϊpnode��ֵ
	pnode -> score = 90;

	head -> next = pnode;//ʹͷ��nextָ��ָ��pnode
	pnode ->next = NULL;//ʹĩβ��nextָ��ָ��NULL

	return 0;
}