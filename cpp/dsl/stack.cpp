#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack
{
private:
	int top;
	
public:
	int stack[MAX];
	Stack() {top =-1;}
	bool push(int);
	int pop();
	int peek();
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
	cout << element << " pushed to the stack."<< endl;
	return true;
}

int Stack::pop()
{
	if (top<0)
	{
		cout << "Stack Underflow";
		return 0;
	}

	top--;
	return stack[top];
}

int Stack::peek()
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

int main(){
	Stack s1;
	s1.push(5);
	s1.push(59);
	cout << "Element: " << s1.peek() << endl;
	cout << "is empty (0=false, 1=true): " << s1.isEmpty() << endl;
	cout << "Popped Element: " << s1.pop() << endl;
	cout << "Element: " << s1.peek() << endl;
}
