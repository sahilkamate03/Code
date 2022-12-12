#include <bits/stdc++.h>
using namespace std;

class Node{
private:
	int data;
	Node* next;
public:
	Node() {
		this->data =0;
		this->next =NULL;
	}

	Node(int data){
		this->data =data;
		this->next =NULL;
	}

	friend class LinkedList;
};

class LinkedList{
private:
	Node* head;
public:
	LinkedList () {head =NULL;}

	int count();
	void display();
	void create(int);
	void insert(int, int);
	void display_reverse();
	void deletePosition(int);
};

int LinkedList :: count()
{
	int count =0;
	Node* prevNode =head;
	while (prevNode != NULL) prevNode =prevNode->next, count++;

	return count;
}

void LinkedList :: display()
{
	if (head==NULL) {cout << "Head is empty." << endl; return;}

	Node* node =head;
	while (node != NULL)
	{
		cout << node->data << " ";
		node =node->next;
	}
	cout << endl;
}

void LinkedList :: create(int  sizeOfLinkedList)
{
	cout << "Enter the value: ";
	for (int i=0; i<sizeOfLinkedList; i++)
	{
		Node* prevNode;
		int data;
		cin >>data;
		Node* new_node = new Node(data);

		if (head==NULL){
			head =new_node;
			prevNode =new_node;
		}
		else{
			prevNode->next =new_node;
			prevNode =new_node;
		}
	}
}

void LinkedList :: insert(int data, int position)
{
	Node* prevNode =head;
	Node* new_node = new Node(data);
	
	for (int i = 0; i < position; ++i)
	{
		prevNode =prevNode->next;
	}

	new_node->next =prevNode->next;
	prevNode->next =new_node;
}

void LinkedList :: deletePosition(int position)
{
	Node* prevNode;
	Node* currentNode =head;
	Node* nextNode;

	for (int i = 0; i <= position; ++i)
	{
		prevNode = currentNode;
		currentNode = currentNode->next;
		nextNode = currentNode->next;
	}

	delete currentNode;
	prevNode->next = nextNode;
}

void LinkedList :: display_reverse()
{ 
    Node *prevNode =head;
    head =head->next;
    if(head!=NULL)
    	display_reverse();
    head =prevNode;
    cout<<head->data<<" ";
}
// void printLL(Node* n)
// {
// 	while(n)
// 	{
// 		cout << n-> data << " ";
// 		n = n->next;
// 	}
// }

// void insertAfter(Node* n, int data, int index)
// {
	
// 	Node* new_node =new Node();
// 	new_node->data =data;

// 	int count =0;
// 	while(count<index-1)
// 	{	
// 		n =n->next;
// 		count++;
// 	}

// 	new_node->next = n->next;
// 	n->next =new_node;
// }

// void push(Node** head_ref, int data)
// {
// 	Node* new_node = new Node();
// 	new_node->data =data;
// 	new_node->next =(*head_ref);
// 	(*head_ref) = new_node;
// }

int main(){
	LinkedList l1;
	
	int sizeOfLinkedList;
	cout << "Enter the size of LinkedList: ";
	cin >> sizeOfLinkedList;

	l1.create(sizeOfLinkedList);
	l1.insert(4,1);
	l1.display();
	l1.deletePosition(1);
	l1.display();
	l1.display_reverse();
	cout << l1.count() << endl;
}
