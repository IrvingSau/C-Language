#include "list.h"
#include <stdio.h> 
#include<stdlib.h>

int main() 
{ 
	Node *head = 0;
	for(int i=0; i<0; i++)
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
	//DestroyList(head);

}  

bool isEmpty(Node* head){
	if(head->next == NULL)
		return true;
	else
		return false;
}

Node* InsertNode(Node** phead, int index, double x){
	if(index < 0) return 0;//Handle Exception

	int currIndex = 0;//Initialize the currIndex

	Node* currNode = *phead;//Let currNode point to the first node of LinkedList

	while(currIndex < index && currNode){
		currIndex++;
		currNode = currNode->next;
	}

	Node* newNode = (Node *)malloc(sizeof(Node));

	//2 situation: first, insert in the front. Second, insert in the list
	if(index == 0){
		newNode ->data = x;
		newNode->next = *phead;
		*phead = newNode;
	}else if(index > 0){
		newNode->data = x;
		newNode->next = currNode->next;
		currNode->next = newNode;
	}
	return newNode;
}

int FindNode(Node* head, double x){
	//initialize the index
	int index = 0;

	//initialize the current node and let it points to head
	Node* currNode = head;

	while(currNode){
		//every time we move the pointer currNode, we make index plus
		index++;

		//if this currNode->data is not x, we move currNode to next node
		if(currNode->data != x)
			currNode = currNode->next;
		//if this currNode->data is x, we return the index
		else
			return index;
	}
	//if we have not found x in linked list, we return 0
	return 0;
}

int DeleteNode(Node** phead, double x){
	
	if(*phead == NULL){
		printf("The list is empty.");
		return 0;
	}

	double value = x;

	Node* priorNode = *phead;
	Node* currNode = *phead;

	int currIndex = 1;
	int targetIndex;

	//Find the preducessor of currNode
	while(priorNode){
		targetIndex++;
		if(priorNode->next)
	}

	//Fine the node we want to delete
	while(currIndex < targetIndex){
		currIndex++;
		currNode = currNode->next;
	}

	if(currNode->next = NULL)
		currNode ->next = NULL;
	//if we want to delete, we need to make precessor->next = sucessor->next
	else
		currNode->next = currNode->next->next;
	//free(currNode);

	return currIndex;
}

void DisplayList(Node* head){
	Node* currNode = head;
	//do{
	//	printf("%lf", currNode->data);
	//	currNode = currNode->next;
	//}while(currNode->next != 0);
	while(currNode != NULL){
		printf("%lf\n", currNode->data);
	 	currNode = currNode->next;
	}
}