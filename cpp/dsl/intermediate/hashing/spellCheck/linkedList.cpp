#include <bits/stdc++.h>
#include "linkedList.h"

using namespace std;

void LinkedList::appendValue(string word)
{
	Node* newNode = new Node(word);
	if (head==NULL)
	{
		head =newNode;
		return;
	}

	Node* currentNode =head;
	while(currentNode->next!=NULL)
	{
		currentNode =currentNode->next;
	}

	currentNode->next =newNode;

}

void LinkedList::deleteValue(string word)
{
	Node* currentNode =head;

	if (head->word == word)
	{
		head =currentNode->next;
		delete currentNode;
		return;
	}

	Node* prevNode=head;

	while(currentNode->next!=NULL)
	{
		currentNode =currentNode->next;
		if (currentNode->word == word)
			break;
		prevNode= prevNode->next;
	}

	if (currentNode->word==word)
	{
	prevNode->next =currentNode->next;
	delete currentNode;
	}
}

void LinkedList::display()
{

	Node* currentNode =head;

	while(currentNode->next !=NULL)
	{
		cout << currentNode->word << " ";
		currentNode =currentNode->next;
	}

	cout << currentNode->word << endl;
}
