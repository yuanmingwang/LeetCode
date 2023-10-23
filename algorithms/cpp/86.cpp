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

        time O(N)
        space O(N)
    */
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1 = new ListNode();
        ListNode *dummy2 = new ListNode();
        ListNode *p1 = dummy1, *p2 = dummy2;
        ListNode *p = head;
        
        while(p)
        {
            //// node less than x come before, add it into p1
            if(p->val < x)
            {
                p1->next = p;
                p1 = p1->next;
            }
            else
            {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }
        //// connect two lists
        p1->next = dummy2->next;
        //// make sure the last element points to null
        p2->next = NULL;
        
        return dummy1->next;
    }
};