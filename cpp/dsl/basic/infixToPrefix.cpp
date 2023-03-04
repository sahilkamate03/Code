#include <bits/stdc++.h>
#include "stack.h"
using namespace std;

bool isOperator(char c) 
{
    switch (c)
    {
    case '+':
        return true;
    case '-':
        return true;
    case '*':
        return true;
    case '/':
        return true;
    case '^':
        return true;
    case '(':
        return true;
    case ')':
        return true;
    default:
        return false;
    }
}

int getPriority(char c)
{
    if (c == '+' || c == 'i')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;

    return 4;
}

// void reverseString(char str[])
// {
//     int n =strlen(str);
//     Stack reverse;

//     for (int i=0; i<=n; i++)
//         reverse.push(str[i]);

//     int i=0;
//     while (!reverse.isEmpty())
//         str[i]=reverse.pop(), i++;

// }

string infixToPrefix(string str)
{
    string ans ="";
    Stack st;
    int prevPriority =0, currentPriority =0;

    for (int i=str.size()-1; i>-1; i--)
    {
        char ch =str[i];
        // cout << ans << " " << ch << " " << st.peek() << endl;

        if (!isOperator(ch))
        {
            ans +=ch;
            continue;
        }

        currentPriority =getPriority(ch);

        if (ch == '(')
        {
            int n =i;
            char tempC =st.pop();
            cout << tempC << endl; 
            ans +=tempC;
            while(tempC!=')')
            {
                tempC =st.pop();
            cout << tempC << endl; 
                
                ans +=tempC;
            }
            st.pop();
            continue;
        }

        else if (currentPriority>=prevPriority)
        {
            st.push(ch);
            prevPriority =currentPriority;
            continue;
        }

        st.push(ch);

    }

    cout << st.peek() << endl;
    while (!st.isEmpty())
        ans +=st.pop();
    return ans;
}

int main(){
    
    string str = "(a+b)*c";

    str = infixToPrefix(str);
    cout << str;
}
