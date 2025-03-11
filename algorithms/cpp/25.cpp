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
    
            Similar approach & framework as 92. Reverse Linked List II
            Check it for detailed explanation.
            
            time O(n)
            space O(1)
        */
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode dummy = ListNode(0, head);
            ListNode *prev = &dummy, *curr = head, *nxt = nullptr;
            ListNode *cursor = nullptr;
    
            // use while(true) to mimic recursion
            while(true)
            {
                //// base case: we don't need to reverse the list if the remaining node is less than k
                cursor = prev;
                for(int i = 0; i < k; ++i)
                {
                    if(cursor->next == nullptr)
                        return dummy.next;
                    cursor = cursor->next;
                }
    
                //// reverse
                for(int i = 0; i < k - 1; ++i)
                {
                    // reset nxt to the next obj to be swapped
                    nxt = curr->next;
                    // switch curr and curr->next
                    curr->next = nxt->next;
                    // prev->next points to the curr start of the interval, and it's the next of nxt
                    nxt->next = prev->next;
                    prev->next = nxt;
                    // now prev points to the left'th object (nxt)
                    // curr points to the first obj that need to be swaped to the right.
                }
                // set prev and curr
                // during the end of for loop, curr points to the right most node after swap
                // this will be the prev of the next group's starting node and curr will be curr->next
                prev = curr;
                curr = curr->next;
            }
        }


        // 2. -------------------------------------------------------------------------------------------------------------- 
        /** 
            Linked List
            Recursive solution
            
            time O(n)
            space O(n)
        */
        ListNode* reverseKGroup(ListNode* head, int k) {
            // recursive approach
            ListNode *cursor = head;
            // we don't nned to reverse the list if the remaining node is less than k, return head
            for(int i = 0; i < k; ++i)
            {
                if(cursor == nullptr) return head;
                cursor = cursor->next;
            }
            // reverse
            ListNode *prev, *cur = head, *next;
            for(int i = 0; i < k; ++i)
            {
                // reverse
                next = cur->next;
                cur->next = prev;
                // set pointers point to the next node
                prev = cur;
                cur = next;
            }
            // now prev points to the new head
            // cur/next points to the head of the remaining old list
            // we want head->next points to the reversed of the remaining k node
            head->next = reverseKGroup(cur, k);
            return prev;
        }
    };