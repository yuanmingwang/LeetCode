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
        /** 2. Add Two Numbers
            Linked List, Two Pointers
    
            time O(N)
            space O(1)
        */
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *dummy = new ListNode();
            ListNode *p = dummy;  // use p to construct the res node
            ListNode *p1 = l1, *p2 = l2;
            int carry = 0;
    
            while(p1 or p2 or carry > 0)    // we need to handle carry even if p1 and p2 is null
            {
                //// add carry to current val
                int val = carry;
                //// add p1 and p2 to val if p1 and p2 exist
                if(p1)
                {
                    val += p1->val;
                    p1 = p1->next;
                }
                if(p2)
                {
                    val += p2->val;
                    p2 = p2->next;
                }
    
                //// handle carry
                carry = val / 10;   // in cpp division rounding toward zero
                val = val % 10;
                p->next = new ListNode(val);
                p = p->next;
            }
    
            ListNode *res = dummy->next;
            delete dummy;   // free memory
            return res;
        }
    };