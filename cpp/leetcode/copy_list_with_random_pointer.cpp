/*

*/
// Definition for a Node.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
    friend class Solution;
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *newHead =new Node(head->val);
    
        Node *start =head;
        Node *newStart =newHead; 
        while(start->next)
        {
            start =start->next;
            Node *temp =new Node(start->val);
            newStart->next =temp;
            newStart =newStart->next;

            if (!start->next)
            {
                start->next =head;
                newStart->next =newHead;
            }
        }

        start =head;
        newStart =newHead;

        while (newStart != newHead)
        {
            if (!start->random)
            {
                start =start->next;
                newStart =newStart->next;
                continue;
            }

            Node *temp1 =start;
            Node *temp2 =newStart;

            while (temp1!=start->random)
            {
                temp1 =temp1->next;
                temp2 =temp2->next;
            }

            newStart->random =temp2;
            start =start->next;
            newStart =newStart->next;

        }

        while (newStart->next!=newHead)
        {
            start =start->next ;
            newStart =newStart->next ;
        }
        start->next =nullptr;
        newStart->next =nullptr;
        
        return newHead;
    }
};

int main()
{
    Node *head =new Node(1);
    Node *second =new Node(2);

    head->next =second;
    head->random =second;

    second->random =second;

    Solution s;
    s.copyRandomList(head);
}
