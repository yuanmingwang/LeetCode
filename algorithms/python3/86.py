# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    """ 
        86. Partition List
        Linked List, Two Pointers

        time O(N)
        space O(N)
    """
    def partition(self, head: ListNode | None, x: int) -> ListNode | None:
        dummy_small = ListNode(-1)
        dummy_large = ListNode(-1)
        p1 = dummy_small
        p2 = dummy_large
        p = head

        while p is not None:
            val = p.val
            if val < x:
                p1.next = p
                p1 = p1.next
            elif val >= x:
                p2.next = p
                p2 = p2.next
            p = p.next
        ## connect two lists
        p1.next = dummy_large.next
        ## make sure the last element points to null 
        p2.next = None

        return dummy_small.next
