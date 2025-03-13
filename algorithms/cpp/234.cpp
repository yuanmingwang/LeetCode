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
            Linked List, Two Pointers, Stack, Recursion
    
            Recursive solution
            
            time O(n)
            space O(n)
        */
        bool isPalindrome(ListNode* head) {
            ListNode *left = head, *right = head;
            return traverse(right, left);
        }
    
        bool traverse(ListNode* right, ListNode* &left)
        {
            //// base case
            if(right == nullptr)
                return true;
    
            //// Pre-order traversal code
    
            //// traverse
            bool res = traverse(right->next, left);
    
            //// Post-order traversal code
            // check palindrome
            res = res && left->val == right->val;
            left = left->next;
            
            return res;
        }


        /** 2.---------------------------------------------------------------------------------------------------------------------------------------- **/
        /** 
            Linked List, Two Pointers

            Iterative solution

            Approach:
                1. Use slow and fast pointers to find the middle point of the list
                    If the fast pointer doesn't point to null, the length of the linked list is an odd number, 
                    and slow should goes one step further because it will points to the middle point in this case, and we want to reverse the node after the middle point
                2. Reverse the second half of the list starting from the slow pointer
                3. Compare the palindrome
            
            time O(n)
            space O(1)
        */
        bool isPalindrome(ListNode* head) {
            ListNode *slow = head, *fast = head;

            //// 1. find the node that we want to start reversing
            while(fast != nullptr and fast->next != nullptr)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            // move slow one step ahead if the length of the list is odd. see above for explanation
            if(fast != nullptr)
                slow = slow->next;

            //// 2. reverse the second half of the list
            ListNode* left = head;
            ListNode* right = reverse(slow);
            //// 3. Compare the palindrome
            // need to use right because the middle point is not reversed, so the reversed part is shorter than the unreversed part
            while(right != nullptr)
            {
                if(left->val != right->val)
                    return false;
                left = left->next;
                right = right->next;
            }
            return true;
        }

        //// reverse the list starting from head, and return the new head
        //// Similar approach & framework as 206. Reverse Linked List
        ListNode* reverse(ListNode* head)
        {
            ListNode* prev = nullptr, *curr = head, *nxt = nullptr;
            while(curr)
            {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            // now, prev points to the head of the reversed node
            return prev;
        }
    };