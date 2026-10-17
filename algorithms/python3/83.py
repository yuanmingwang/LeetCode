# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    """ 
        83. Remove Duplicates from Sorted List
        Linked List, Two Pointers

        We let the slow pointer wait behind, while the fast pointer fast goes ahead to explore. 
        When fast finds a non-duplicate element, we assigns it to slow and then slow moves forward by one step.

        time O(n)
        space O(1)
    """ 
    def deleteDuplicates(self, head: ListNode | None) -> ListNode | None:
        if head is None:
            return head
        slow = head
        fast = head
        while fast is not None:
            ## find a new element, connect it to the current slow
            if fast.val != slow.val:
                slow.next = fast
                slow = slow.next
            fast = fast.next
        ## disconnect from the following duplicate elements
        slow.next = None
        return head