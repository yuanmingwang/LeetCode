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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(), *p = dummy;
        ListNode *p1 = list1, *p2 = list2;
        
        //// if there is node remaining in both lists
        while(p1 && p2)
        {
            //// p2 is smaller, connect it to p first
            if(p1->val > p2->val)
            {
                p->next = p2;
                p2 = p2->next;
            }
            else
            {
                p->next = p1;
                p1 = p1->next;
            }
            p = p->next;
        }
        //// one of the list has no remaining node here
        //// we need to merge the list with remaining nodes into p
        if(p1)
            p->next = p1;
        if(p2)
            p->next = p2;
        
        // dummy->next points to the start of the merged list
        return dummy->next;
    }
};