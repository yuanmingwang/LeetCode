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
    /** 23. Merge k Sorted Lists
        Linked List, Heap (Priority Queue)

        time O(logK * N), N = # elements in one list, K = # lists
        space O(N)
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *dummy = new ListNode();
        ListNode *p = dummy;
        //// init the minimum priority queue
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        // push the head of each list into the pq
        for(auto &head : lists)
        {
            if(head)    // prevent adding null pointer to the pq if we have [[]] as input
                pq.push(head);
        }

        //// 1.get the smallest node
        //// 2.connect it to the cur node
        //// 3.add the next node to the pq
        //// 4.update cur
        ListNode *node;
        while(!pq.empty())
        {
            // 1.
            node = pq.top();
            pq.pop();
            // 2.
            p->next = node;
            // 3.
            if(node->next)
                pq.push(node->next);
            // 4.
            p = p->next;
        }
        return dummy->next;
    }

    //// overload Comparator
    struct compare
    {
        //// if p1->val < p2->val == true, priority queue will put p1 in front of p2
        bool operator() (const ListNode *p1, const ListNode *p2)
        {
            // we need a minimum priority queue(with the smallest element on the top)
            // so the comparator should be 'greater<T>'
            return p1->val > p2->val;
        }
    };
};