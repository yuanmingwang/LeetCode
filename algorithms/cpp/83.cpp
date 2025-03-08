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
    
            We let the slow pointer wait behind, while the fast pointer fast goes ahead to explore. 
            When fast finds a non-duplicate element, we assigns it to slow and then slow moves forward by one step.
    
            time O(n)
            space O(1)
        */
        ListNode* deleteDuplicates(ListNode* head) {
            if(head == nullptr)
                return head;
            ListNode *slow = head, *fast = head;
            
            while(fast)
            {
                // find a new element, connect it to the current slow
                if(slow->val != fast->val)
                {
                    slow->next = fast;
                    slow = slow->next;
                }
                fast = fast->next;
            }
            //// disconnect from the following duplicate elements
            slow->next = nullptr;
            return head;
        }
    };