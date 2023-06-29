/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return nullptr;
		int size =0;
		ListNode* start =head;
		ListNode* cur =head;
		while (start->next)
		{
			size++;
			start =start->next;
		}
	
		k %=size+1;
		size -=k;
		while (size--)
		{
			cur =cur->next;
		}

		start->next =head;
		head =cur->next;
		cur->next =nullptr;

		return head;	
    }
};

