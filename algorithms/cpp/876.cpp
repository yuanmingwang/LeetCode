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
            
            time O(n)
            space O(1)
        */
        ListNode* middleNode(ListNode* head) {
            ListNode *p_fast = head, *p_slow = head;
    
            while(p_fast and p_fast->next)
            {
                //// p_fast moves 2 times faster than p_slow
                p_fast = p_fast->next->next;
                p_slow = p_slow->next;
            }
    
            return p_slow;
        }
    };