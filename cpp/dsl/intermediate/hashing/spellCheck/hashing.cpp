#include <bits/stdc++.h>
#include "hashing.h"

using namespace std;

int hashTable::hash_fxn(string word)
{
	int p =53;
	int value =0;
	
	int i=0;
	for (char ch : word)
	{
		int c = (int) ch;
		if (c>96 && c<123)
			c -=96;
		else if (c>64 && c<91)
			c-=38;
		
		value = value + (c * (int)pow(p,i));
	}	
	
	value = value %MOD;
	return value;
}


void hashTable::insert(string word)
{
	Node* newNode =new Node(word);	
	int hashValue =hash_fxn(word);	

	if (arr[hashValue] == NULL)
	{
		arr[hashValue] = newNode;
		return;
	}

	Node* currentNode =arr[hashValue];

	while (currentNode->next != NULL)
	{
		currentNode =currentNode->next;
	}

	currentNode->next =newNode;
}

void hashTable::display()
{
    for (int i=0; i<MOD; i++)
    {	
	    Node* currentNode =arr[i];
	    cout << i << ". ";
	    if (currentNode == NULL)
	    {
	    	cout << "\n";continue;
	    }

	    while(currentNode->next != NULL)
	    {
	        cout << currentNode->word << " ";
	        currentNode =currentNode->next;
	    }
   		
   		cout << currentNode->word << endl;
    }
}

bool hashTable::spellCheck(string word)
{
    int hashValue =hash_fxn(word);
    Node* currentNode =arr[hashValue];
    
    if (currentNode == NULL)
        return false;

    while(currentNode->next != NULL)
    {
        if (currentNode->word == word)
            return true;
        currentNode =currentNode->next;
    }
    
    if (currentNode->word == word)
            return true;
    
    return false;
}
