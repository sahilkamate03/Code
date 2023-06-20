
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
		void reverseList(ListNode* head)
		{
			ListNode* back =nullptr; ListNode* current =head; ListNode* front;
			while(current)
			{
				front =current->next;
				current->next =back;

				back =current;
				current =next;
			}
		}

		ListNode* reverseKGroup(ListNode* head, int k) {
			ListNode* start = new ListNode();
			start->next =head;
			ListNode* front =start;
			ListNode* current =start;
			while (front->next)
			{
				int n=0;
				ListNode* back =current; current =current->next; 
				while(n!=k) 
				{
					n++;
					front =front->next;
				}

				if (n!=k)
				{
					return head;
				}

				reverseList(current);
				current->next =front->next;
				back->next =front;

			}   

			return head;
		}
};
