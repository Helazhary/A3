#pragma once
#include <iostream>
#include <vector>

using namespace std;
struct node
{
	int occurences = 1;
	int num;
	node* next = NULL;
};

class LinkedList
{
protected:
	//-----------node struct and head pointer--------------------
	
	node* head = NULL;
	int size = 0;
public:
//----------------------linked list functions---------------------
	void addnodeStart(int n);
	node* getPointToLast();
	void addnodeEnd(int n);
	void addnodeToX(int n,int x);
	void removenode(int position);
	void printlist();
	int sum();
	LinkedList(){}
	LinkedList(node* h) {
		head = h;
	}
	LinkedList(const LinkedList& ll) {
		size = ll.size;
		head = ll.head;
	}
	
	


};
