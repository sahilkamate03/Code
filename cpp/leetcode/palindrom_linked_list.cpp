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
    bool isPalindrome(ListNode* head) {
	stack<ListNode*> st;
	ListNode* start =head;
	int count =0;

	while (start)
	{
		count++;
		st.push(start);
		start =start->next;
	}
	start =st.top();
	count /=2;
	while (count--)
	{
		if (start->val !=head->val)
		{
			return false;
		}
		st.pop();
		start =st.top();
		head =head->next;
	}

	return true;
}
};

