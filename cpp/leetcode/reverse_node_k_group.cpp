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
			ListNode* prev_p = NULL;
			ListNode* current_p = head;
			ListNode* next_p;

			while(current_p) {

				next_p = current_p->next;
				current_p->next = prev_p;

				prev_p = current_p;
				current_p = next_p;
			}

			head = prev_p;
		}

		ListNode* reverseKGroup(ListNode* head, int k) {
			if (k==1) return head;

			ListNode* start = new ListNode();
			start->next =head;
			ListNode* front =head;
			ListNode* middle =start;
			while (front)
			{
				int n=0;
				ListNode* back =middle; 
				ListNode* temp =nullptr;
				while(n!=k-1 && front) 
				{
					n++;
					front =front->next;
				}

				if (n!=k-1 || !front)
				{
					return start->next;
				}

				temp =front->next;
				middle =middle->next;
				front->next =nullptr;
				reverseList(middle);
				back->next =front;
				middle->next =temp;
				front = temp;
			}   

			return start->next;
		}
};

