#include <bits/stdc++.h>
using namespace std;
 
bool isOperator(char c){ return (!isalpha(c) && !isdigit(c));}

int priority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    return 0;
}

bool isOperand(char x)
{
   return (x >= 'a' && x <= 'z') ||    (x >= 'A' && x <= 'Z');
}

 
string In_to_Pre(string infix)
{
    stack<char> operators;
    stack<string> operands;
 
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            operators.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (!operators.empty() &&
                   operators.top() != '(') {
                string op1 = operands.top();
                operands.pop();

                string op2 = operands.top();
                operands.pop();
 
                char op = operators.top();
                operators.pop();
 
                string tmp = op + op2 + op1;
                operands.push(tmp);
            }
 
            operators.pop();
        }
 
        else if (!isOperator(infix[i])) { operands.push(string(1, infix[i]));
        }
 
        else {
            while (!operators.empty() &&
                   priority(infix[i]) <=
                     priority(operators.top())) {
 
                string op1 = operands.top();
                operands.pop();
 
                string op2 = operands.top();
                operands.pop();
 
                char op = operators.top();
                operators.pop();
 
                string tmp = op + op2 + op1;
                operands.push(tmp);
            }
 
            operators.push(infix[i]);
        }
    }
 
    while (!operators.empty()) {
        string op1 = operands.top();
        operands.pop();
 
        string op2 = operands.top();
        operands.pop();
 
        char op = operators.top();
        operators.pop();
 
        string tmp = op + op2 + op1;
        operands.push(tmp);
    }
    return operands.top();
}
 

string Pst_to_Pre(string post_exp)
{
	stack<string> s;
	int length = post_exp.size();

	for (int i = 0; i < length; i++) {
		if (isOperator(post_exp[i])) {
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();

			string temp = post_exp[i] + op2 + op1;
			s.push(temp);
		}
		else {
			s.push(string(1, post_exp[i]));
		}
	}
	string ans = "";
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	return ans;
}


string Pst_to_In(string exp)
{
    stack<string> s;
 
    for (int i=0; exp[i]!='\0'; i++)
    {
        // Push operands
        if (isOperand(exp[i]))
        {
           string op(1, exp[i]);
           s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] +
                   op1 + ")");
        }
    }
    return s.top();
}

int main()
{
    string s ;
    cout<<"enter the infix expression : ";
    cin>>s;
    cout << "prefix expression is : "<<In_to_Pre(s) <<endl;
    cout<<endl;
    
    string exp ;
    cout<<"enter the postfix expression : ";
    cin>>exp;

    cout << "infix expression: "<<Pst_to_In(exp)<<endl;
    cout << "prefix expression: "<<Pst_to_Pre(exp)<<endl;

    return 0;
}