#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
	int data;
	Node* next;
public:
	Node() {this->data =0; this->next=NULL;}
	Node(int data) {this->data=data; this->next=NULL;}
	friend class LinkedList;
};

class LinkedList
{
private:
	Node* head;
public:
	LinkedList() {head=NULL;}
	void create();
	void display();
};

void LinkedList::create()
{
	cout << "Enter the size of LinkedList: ";
	int size; cin>>size;

	cout << "Enter the value: ";
	for(int i=0; i<size; i++)
	{
		Node* prevNode;
		int value; cin>>value;

		Node* new_node = new Node(value);
		if (head=NULL)
		{
			head = new_node;
			prevNode =new_node;
		}
		else
		{
			prevNode->next =new_node;
			prevNode =new_node;
		}

	}
}

void LinkedList::display()
{
	if (head=NULL) {cout << ""}
	Node* pointer =head;
	while (pointer!=NULL)
	{
		cout << pointer->data << " ";
		pointer =pointer->next;
	}
	cout << endl;
}

int main(){
	LinkedList l;
	l.create();	
	l.display();
}
