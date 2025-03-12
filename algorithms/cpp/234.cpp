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
    };