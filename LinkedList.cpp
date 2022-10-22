#include "LinkedList.h"



void LinkedList::addnodeStart(int n)
{
	node* newnode = new node;
	newnode->num = n;
	
	newnode->next = head;
	head = newnode;
	size++;
}
node* LinkedList::getPointToLast() {
	node* p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	
	return p;
}
void LinkedList::addnodeEnd(int n) {

	if (head == NULL) {
		addnodeStart(n);
	}
	else {
		node* newnode = new node;
		newnode->num = n;
		newnode->next = NULL;

		node* cursor = head;
		while (cursor->next != NULL) {
			cursor = cursor->next;
		}
		cursor->next = newnode;
		size++;
	}
	
}

void LinkedList::addnodeToX(int n,int x) {
	if (x == 0) {
		addnodeStart(n);
	}
	else if (head == NULL) {
		cout << "list was empty. Adding to start."<<endl;
		addnodeStart(n);
	}else {
		node* newnode = new node;
		newnode->num = n;

		int count = 0;
		node* p = head;
		while (p->next != nullptr && count <x-1 ) {
			p = p->next;
			count++;
		}
		if (count != x) {
			cout << "Index out of range. Adding"<< n<<" to end." << endl;
		}
		newnode->next = p->next;
		p->next = newnode;
		size++;

	}
}


void LinkedList::removenode(int position)
{
	
	if (size == 0) {
		cout << "Nothing to delete. LL is empty." << endl;
	}else if (position == 0) {
		node* temp = head;
		head = head->next;
	}
	else if(position <size){
		node* p = head;
		for (int i = 0;i < position-1;i++) {
			p = p->next;
		}
		node* temp = p->next;
		p->next = p->next->next;
	}
}

void LinkedList::printlist()
{
	node* cursor = head;
	while (cursor != NULL)
	{
		cout <<"Integer value:" << cursor->num <<"\tOccurences: "<<cursor->occurences <<endl;
		cursor = cursor->next;
	}
}

int LinkedList::sum()
{
	int vsum = 0;
	node* cursor = head;
	while (cursor != NULL)
	{
		vsum += cursor->num;
		cursor = cursor->next;
	}
	return vsum;
}
