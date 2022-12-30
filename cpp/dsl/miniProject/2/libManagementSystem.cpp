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


int homeScreen()
{
	cout << "\n\n\t\t<<=========================>>";
	cout << "\n\t\t>>LIBRARY MANAGEMENT SYSTEM<<";
	cout << "\n\t\t<<=========================>>";
	cout << "\n\n\t\t1.Librarian\n\t\t2.Studnet"<< endl;

	cout<< "\n\t\tEnter the choice: ";
	int choice; cin >>choice;

	return choice;
}

void studentLogin()
{
	system("cls");
	cout << "Enter username: ";
	string username; cin >> username; 
	cout << "Enter password: ";
	string password; cin >> password;


	cout << "studentLogin" << endl;
}

void librarianLogin()
{
	system("cls");
	cout << "librarianLogin" << endl;
}

int login(int choice)
{
	if (choice==1) studentLogin();
	else if (choice==2) librarianLogin();
	else cout<< "Wrong input!!! Application Closing...."<<endl;
}

int main(){
	login(homeScreen());

}
