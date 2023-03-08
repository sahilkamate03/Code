#ifndef HASHING_H
#define HASHING_H

#include <bits/stdc++.h>
#define MOD 53	
using namespace std;

class Node
{
private:
	string word;
    Node* next;
    
public:
	Node() : word{"default"}, next{NULL} {};
	Node(string word) : word{word}, next{NULL} {};
	
	friend class hashTable;
};

class hashTable
{
private:
	Node* arr[MOD]={NULL};

public:
	int hash_fxn(string);
	void insert(string);
	void multipleInsert(string);
	void display();
	bool spellCheck(string);
};

#endif