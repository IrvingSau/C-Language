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
	//Test

	printf("OldList: \n");

	DisplayList(head);

	printf("The amount of 4 is %d\n", DeleteNodes(&head, 4));
	
	printf("NewList: \n");
	DisplayList(head);

	printf("After remove duplicates: \n");

	RemoveDuplicates(&head);
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
	if (index > 0 && currNode == 0) return 0;

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
	//Handle exception
	if(*phead == NULL){
		printf("The list is empty.");
		return 0;
	}

	Node* priorNode = *phead;
	Node* targetNode;

	int priorIndex = 1;

	//Fine the predesessor of the target node we want to delete
	while(priorIndex < FindNode(*phead, x) - 1){
		priorIndex++;
		priorNode = priorNode->next;
	}

	//Confirm the target node that we want to delete
	targetNode = priorNode->next;

	//Judge if the target node is the last node in the linked list
	if(targetNode->next == NULL){
		priorNode ->next = NULL;
		free(targetNode);
	}else{
		priorNode->next = targetNode->next;
		free(targetNode);
	}

	//make sure the target index is right(target index is one more than prior index)
	int currIndex = priorIndex+1;

	return currIndex;
}

int DeleteNodes(Node** phead, double x){
	//Handle exception
	if(*phead == NULL){
		printf("The list is empty.");
		return 0;
	}

	//Use countNode to calculate the amount of target element
	int amountOfElement = 0;
	Node* countNode = *phead;
	while(countNode){
		if(countNode->data == x)
			amountOfElement++;
		countNode = countNode->next;
	}

	//Use for loop to delete all element we want to delete in the linked list
	for(int i = 0; i < amountOfElement; i++){

		int index = 0;

		//initialize the current node and let it points to head
		Node* currNode = *phead;

		while(currNode){
			//every time we move the pointer currNode, we make index plus
			index++;
			//if this currNode->data is not x, we move currNode to next node
			if(currNode->data != x){
				currNode = currNode->next;
			}else
				break;
		}

		//initialize the target node and the priorNode before target node
		Node* priorNode = *phead;
		Node* targetNode;

		//Judge if we want to delete the first Node or else
		if(index == 1){
			*phead = currNode->next;
			free(currNode);
		}else{
			int priorIndex = 1;

			//Fine the predesessor of the target node we want to delete
			while(priorIndex < index - 1){
				priorIndex++;
				priorNode = priorNode->next;
			}

			//Confirm the target node that we want to delete
			targetNode = priorNode->next;

			//Judge if the target node is the last node in the linked list
			if(targetNode->next == NULL){
				priorNode ->next = NULL;
				free(targetNode);
			}else{
				priorNode->next = targetNode->next;
				free(targetNode);
			}
		}
	}

	return amountOfElement;
}


void RemoveDuplicates(Node** phead){
	double flag;
	Node* currNodeFlag = *phead;
	Node* currNodeMove = currNodeFlag->next;

	while(currNodeFlag){
		bool isDuplicates = false;
		flag = currNodeFlag->data;
		while(currNodeMove){
			if(flag == currNodeMove->data)
				isDuplicates = true;
			currNodeMove = currNodeMove->next;
		}
		if(isDuplicates)
			DeleteNodes(phead, flag);
	}
}


void DisplayList(Node* head){
	Node* currNode = head;
	while(currNode != NULL){
		printf("%lf\n", currNode->data);
	 	currNode = currNode->next;
	}
}

void DestroyList(Node* head){
	Node* currNode = head;
	Node* temp;
	while(currNode){
		temp = currNode;
		currNode = currNode->next;
		free(temp);
	}
}