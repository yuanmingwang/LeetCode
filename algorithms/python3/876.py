# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    """
        Linked List, Two Pointers
        Slow and Fast Pointers, One pass
        
        time O(n)
        space O(1)
    """
    def middleNode(self, head: ListNode | None) -> ListNode | None:
        p_fast = head
        p_slow = head

        while p_fast is not None and p_fast.next is not None:
            p_fast = p_fast.next.next
            p_slow = p_slow.next
        
        return p_slow