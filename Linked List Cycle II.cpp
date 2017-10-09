/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
// 经典算法，快慢指针
class Solution {
public:
   ListNode *detectCycle(ListNode *head) {
       if(head == NULL) return NULL;
       auto fast = head , slow = head;
       while(true){
	   if(!fast->next || !fast->next->next) return NULL;
	   fast = fast->next->next;
	   slow = slow->next;
	   if(fast == slow) break;
       }
       fast = head;
       while(fast != slow){
	   fast = fast->next;
	   slow = slow->next;
       }
       return fast;
   }
};
