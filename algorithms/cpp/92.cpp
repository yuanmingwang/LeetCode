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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            ListNode *dummy = new ListNode();
            dummy->next = head;
            ListNode *prev = dummy, *nxt = nullptr;
            //// find the position left's prev node
            for(int i = 0; i < left - 1; ++i)
                prev = prev->next;

            ListNode *curr = prev->next;
            //// reverse
            for(int i = left; i < right; ++i)
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
            // possible memory leak of dummy node since it is using new to create, allocates memory from the free store (heap)
            return dummy->next;
        }
    };