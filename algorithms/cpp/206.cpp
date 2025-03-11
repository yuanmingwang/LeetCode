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
            Linked List
            Iterative solution
            
            time O(n)
            space O(1)
        */
        ListNode* reverseList(ListNode* head) {
            // curr is the current node being traversed, prev is the predecessor node of curr, next is the successor node or curr
            ListNode *prev = NULL, *curr = head, *next = NULL;
    
            while(curr)
            {
                next = curr->next;
                // Reverse node
                curr->next = prev;
                // Update pointer positions
                prev = curr;
                curr = next;
            }
            return prev;
        }


        // 2. -------------------------------------------------------------------------------------------------------------- 

        /** 
        Linked List, Recursion
        Recursive  solution

        For recursive algorithms that follow the "divide and conquer" approach, the most crucial part is clearly defining the recursive function. Specifically, the definition of our reverseList function is as follows:
            Given a node head, the function reverses the linked list starting from head and returns the new head node after reversal.
        
        time O(n)
        space O(n)
        */
        ListNode* reverseList(ListNode* head) {
            // base case: if the linked list is empty or contains only one node, the reversed result is itself
            if(head == nullptr or head->next == nullptr)
                return head;

            // last is the new head
            ListNode *last = reverseList(head->next);
            // head->next points to the next node, so make the next of the next node point to head = reverse the list
            head->next->next = head;
            // break the link
            head->next = NULL;

            // return the new head node after reversing the list
            return last;
        }

    };