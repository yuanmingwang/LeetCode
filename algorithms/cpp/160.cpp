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
    
    
            The key to solving this problem is to make p1 and p2 reach the intersecting node c1 simultaneously through some method.
    
            So, we can let p1 traverse through list A and then start traversing list B, while p2 traverses through list B and then starts traversing list A. 
            This approach effectively "logically" connects the two linked lists.
    
            By doing this, p1 and p2 can enter the common section simultaneously, reaching the intersecting node c1
    
            time O(m + n), m = length of listA, n = length of listB
            space O(1)
        */
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            // p1 points to the head of list A, p2 points to the head of list B
            ListNode *p1 = headA, *p2 = headB;
            
            // the condition is p1 != p2 because there are two cases:
            // 1. two link lists have the same number of nodes before the intersection, p1 and p2 will meet at the intersection
            // 2. two link lists have different number of nodes before the intersection, p1 and p2 will do as planed above, and meet at the interserction in the second traverse
            while(p1 != p2)
            {
                // p1 moves one step ahead, if it reaches the end of list A, switch to list B
                if(p1 == nullptr)
                    p1 = headB;
                else
                    p1 = p1->next;
                
                // p2 moves one step ahead, if it reaches the end of list B, switch to list A
                if(p2 == nullptr)
                    p2 = headA;
                else
                    p2 = p2->next;
            }
            return p1;
        }
    };