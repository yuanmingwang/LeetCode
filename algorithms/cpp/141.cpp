/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        /** 
            Linked List, Two Pointers
            Slow and Fast Pointers, One pass

            If the fast pointer can reach the end of the list, it indicates that there is no cycle in the list. 
            However, if the fast pointer eventually meets the slow pointer, it means fast pointer is moving in circles within the list, indicating the list contains a cycle.
            
            time O(n)
            space O(1)
        */
        bool hasCycle(ListNode *head) {
            // initialize slow and fast pointers to dummy head
            ListNode *dummy = new ListNode();
            dummy->next = head;
            ListNode *p_slow = head, *p_fast = head;

            // stop when the fast pointer reaches the end
            while(p_fast and p_fast->next)
            {
                p_fast = p_fast->next->next;
                p_slow = p_slow->next;
                // slow and fast pointers meet, there is a cycle
                if(p_slow == p_fast)
                    return true;
            }
            // no cycle because the fast pointer reaches the end
            return false;
        }
    };