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
            Slow and Fast Pointers, 
            
            we use the same method in (141. Linked List Cycle) to check if there is a cycle.
            When the fast and slow pointers meet, redirect either pointer to the head of the list, then let them move at the same speed. The node where they meet again will be the start of the cycle.
            Here's a brief explanation of the principle:
                Assume that when the fast and slow pointers meet, the slow pointer slow has taken k steps, then the fast pointer fast must have taken 2k steps:
                fast has taken k more steps than slow, and these extra k steps are essentially fast circling around the cycle, meaning k is a multiple of the cycle's length.
                
                Assume the distance from the meeting point to the start of the cycle is m. 
                the distance from the start of the cycle to the head node head is k - m, because slow pointer has moved k steps and is m steps in front of the start of the cycle.
                meaning if you move k - m steps from head, you reach the start of the cycle.

                Interestingly, if you continue moving k - m steps from the meeting point, you will also reach the start of the cycle. 
                because the fast pointer is m steps in front of the start of the cycle, and k is the length of the cycle.
                so moving k - m steps must reach the start of the cycle(move from the meeting point):

                Therefore, by redirecting either the fast or slow pointer to head and moving both pointers at the same speed, 
                they will meet after k - m steps, and the meeting point will be the start of the cycle.
            
            time O(n)
            space O(1)
        */
        ListNode *detectCycle(ListNode *head) {
            ListNode *dummy = new ListNode();
            dummy ->next = head;
            ListNode *slow  = dummy, *fast = dummy;

            // stop when the fast pointer reaches the end
            while(fast and fast->next)
            {
                fast = fast->next->next;
                slow = slow->next;

                // slow and fast pointers meet, there is a cycle
                if(slow == fast)
                {
                    // re-point to the head node
                    // move fast and slow pointers at the same speed, and the meeting point is the cycle's starting point
                    slow = dummy;
                    while(slow != fast)
                    {
                        slow = slow->next;
                        fast = fast->next;
                    }
                    return slow;
                }
            }
            // no cycle because the fast pointer reaches the end
            return nullptr;
        }
    };