#include "stdafx.h"
#include "string"
#include<vector>
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;


//A->B->C->D->E->f->g

//B->A->D->C->F->E->G


struct Node
{
	int data;
	struct Node* next;
	Node(int info)
	{
		data = info;
		next = NULL;

	}
};

Node* createList()
{
	Node* head;
	head = new Node(1);
}

//A->B->C->D->E->f->g
//B->A->D->C->F->E->G
Node* SwapPair(Node* head)
{
	if ((head == NULL)|| (head->next = NULL))
		return head;
	
	Node* newHead = head->next;
	
	Node* prev = NULL;
	Node* curr = head;
	Node* next = head->next;
	do
	{
		Node* temp = next->next;
		next->next= 

	}while(1)
	
	return newHead;
}



