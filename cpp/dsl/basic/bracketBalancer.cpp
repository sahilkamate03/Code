#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack
{
private:
	int top;
	
public:
	char stack[MAX];
	Stack() {top =-1;}
	bool push(int);
	char pop();
	char peek();
	bool isEmpty();
};

bool Stack::push(int element)
{
	if (top>=MAX-1)
	{
		cout << "Stack Overflow" << endl;
		return false;
	}

	stack[++top] =element;
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

bool bracketBalancer()
{
	Stack st1;

	cout << "Enter the string: ";
	string str; cin >> str;	

	if (str.length()==1) 
		return false;

	for (char ch : str)
	{
		if (ch!= ')' && ch != '}' && ch != ']') 
		{
			if(!st1.push(ch)) break;
			continue;
		}
		if ((int)st1.peek() == 40 && (int) ch == 41) {st1.pop(); continue;}
		if ((int)st1.peek() == 91 && (int) ch == 93) {st1.pop(); continue;}
		if ((int)st1.peek() == 123 && (int) ch == 125) {st1.pop(); continue;}
		return false;
	}

	if (!st1.isEmpty()) return false;

	return true;
}

int main(){
	(bracketBalancer()) ? cout << "Correct" << endl : cout << "Wrong" << endl;
}
