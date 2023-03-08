#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
	string word;
    Node* next;
    
public:
	Node() : word{"default"}, next{NULL} {};
	Node(string word) : word{word}, next{NULL} {};

	friend class LinkedList;
	friend class hashTable;
};


class LinkedList
{
private:
	Node* head;

public:
	LinkedList() : head{NULL} {};
	void appendValue(string);
	void deleteValue(string);
	void display();
};

#endif
