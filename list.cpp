#include "list.h"
#include <stdio.h> 
#include<stdlib.h>

int main() 
{ 
	Node *head = 0;
	for(int i=0; i<5; i++)
		InsertNode(&head, i, i);
	DisplayList(head);
	for(int i=0; i<5; i++)
		InsertNode(&head, 0, i);
	DisplayList(head);
	for(int i=0; i<7; i+=2){
		int idx = FindNode(head, i);
		if(idx>0)
			printf("%d is at position %d.\n", i, idx);
		else
			printf("%d is not in the list.\n", i);
	}
	DeleteNode(&head, 0);
	DisplayList(head);
	DestroyList(head);
}  

bool isEmpty(Node* head){
	if(head->next == NULL)
		return true;
	else
		return false;
}

Node* InsertNode(Node** phead, int index, double x){
	if(index < 0) return 0;//Handle Exception

	int currIndex = 1;//Initialize the currIndex

	Node* currNode = *phead;//Let currNode point to the first node of LinkedList

	while(currIndex < index && currNode){
		currIndex++;
		currNode = currNode->next;
	}

	Node* newNode = (Node *)malloc(sizeof(Node));

	//2 situation: first, insert in the front. Second, insert in the list
	if(index == 0){
		newNode->next = *phead;
		*phead = newNode;
	}else if(index > 0){
		newNode->next = currNode->next;
		currNode->next = newNode;
	}
	return newNode;
}

int FindNode(Node* head, double x){
	
	int index = 1;

	Node* currNode = head;

	while(currNode->data != x && currNode->next != NULL){
		index++;
		currNode = currNode->next;
	}
	if(currNode->next = NULL)
		return 0;
	else
		return index;
}