#include <bits/stdc++.h>
#include "stack.h"
using namespace std;

#define MAX 1000

bool Stack::push(int element)
{
	if (top>=MAX-1)
	{
		cout << "Stack Overflow" << endl;
		return false;
	}

	stack[++top] =element;
	// cout << element << " pushed to the stack."<< endl;
	return true;
}

char Stack::pop()
{
	if (top<0)
	{
		cout << "Stack Underflow";
		return 0;
	}

	top--;
	return stack[top];
}

char Stack::peek()
{
	if (top<0)
	{
		cout << "Stack is Empty" << endl;
		return 0;
	}

	return stack[top];
}

bool Stack::isEmpty()
{
	return (top<0);
}

