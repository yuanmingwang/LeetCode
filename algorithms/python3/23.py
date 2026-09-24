# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import heapq
class Solution:
    """ 
        23. Merge k Sorted Lists
        Linked List, Heap (Priority Queue)

        time O(logK * N), N = # elements in one list, K = # lists
        space O(N)

        take 3ms to run
    """
    def mergeKLists(self, lists: list[ListNode | None]) -> ListNode | None:
        dummy = ListNode(-1)
        p = dummy
        ## construct minimum priority queue
        pq = []
        ## push the head of each list into the pq
        # i serves as a unique counter (like a tie-breaker index) inside tuple. This prevents Python from ever comparing the ListNode objects directly. if head has the same val, it will compare i instead of head to prevent error
        for i, head in enumerate(lists):
            if head is not None:
                heapq.heappush(pq, (head.val, i, head))
        
        ## 1.get the smallest node
        ## 2.connect it to the cur node
        ## 3.add the next node to the pq
        ## 4.update cur
        while pq:
            val, i, node = heapq.heappop(pq)
            p.next = node
            p = p.next
            if node.next is not None:
                heapq.heappush(pq, (node.next.val, i, node.next))
        
        return dummy.next

""" 
2.---------------------------------------------------------------------------------------------------------------------------------------- 
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import heapq
class Solution:
    """ 
        23. Merge k Sorted Lists
        Linked List, Heap (Priority Queue)

        time O(logK * N), N = # elements in one list, K = # lists
        space O(N)

        This version is slower because it uses lambda function. take 19 ms to run
    """
    def mergeKLists(self, lists: list[ListNode | None]) -> ListNode | None:
        ## Inject the less-than operator directly into LeetCode's ListNode class
        ListNode.__lt__ = lambda self, other: self.val < other.val
        
        dummy = ListNode(-1)
        p = dummy
        ## construct minimum priority queue
        pq = []
        ## push the head of each list into the pq
        for head in lists:
            if head is not None:
                heapq.heappush(pq, (head.val, head))
        
        ## 1.get the smallest node
        ## 2.connect it to the cur node
        ## 3.add the next node to the pq
        ## 4.update cur
        while pq:
            val, node = heapq.heappop(pq)
            p.next = node
            p = p.next
            if node.next is not None:
                heapq.heappush(pq, (node.next.val, node.next))
        
        return dummy.next