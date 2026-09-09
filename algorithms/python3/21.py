# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    """ 
        21. Merge Two Sorted Lists
        Linked List, Two Pointers

        time O(N)
        space O(N)
    """
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(-1)
        p = dummy
        p1 = list1
        p2 = list2

        ## if there is node remaining in both lists
        while p1 is not None and p2 is not None:
            ## p2 is smaller, connect it to p first
            if p1.val > p2.val:
                p.next = p2
                p2 = p2.next
            else:
                p.next = p1
                p1 = p1.next
            p = p.next
        
        ## one of the list has no remaining node here
        ## we need to merge the list with remaining nodes into p
        if p1 is not None:
            p.next = p1
        if p2 is not None:
            p.next = p2
        
        ## dummy.next points to the start of the merged list
        return dummy.next