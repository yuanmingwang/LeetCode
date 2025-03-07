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
        /** 
            Linked List, Two Pointers
            Slow and Fast Pointers, One pass
    
            To remove the nth node from the end, we must first get a reference to the n + 1th node from the end
            
            time O(n)
            space O(1)
        */
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *dummy = new ListNode();
            dummy -> next = head;
            ListNode *p_fast = dummy, *p_slow = dummy;
    
            //// first find the (n + 1)th node from the end
            // move p_fast n + 1 steps ahead
            for(int i = 0; i < n + 1; ++i)
            {
                p_fast = p_fast->next;
            }
            // move both p_fast and p_slow until p_fast reaches the end
            while(p_fast)
            {
                p_fast = p_fast->next;
                p_slow = p_slow->next;
            }
            //// now, p_slow points to the n + 1 node from end, p_slow->next is the node we want to remove
            p_slow->next = p_slow->next->next;
    
            return dummy->next;
        }
    };