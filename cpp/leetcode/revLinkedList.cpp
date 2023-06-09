#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x, ListNode* next) : val(x), next(next) {}
}

ListNode* reverse(ListNode* node)
{
	if (!node)
		return nullptr;
	
	return (new ListNode(node->val, reverse(node->next)));
}

void insert(ListNode* node, int key)
{
	ListNode* newNode =ListNode(key);
	if (!node)
	{
		node =newNode;
		return;
	}

	ListNode* prev =node;
	while (!node)
	{
		prev =node;
		node =node->next;
	}
	
	prevNode->next =newNode;
	return;
}

int main()
{
	
}
