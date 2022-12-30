#ifndef STACK_H
#define STACK_H

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

#endif