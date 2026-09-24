# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    """
        Linked List, Two Pointers
        Slow and Fast Pointers, One pass

        To remove the nth node from the end, we must first get a reference to the n + 1th node from the end

        time O(n)
        space O(n)
    """
    def removeNthFromEnd(self, head: ListNode | None, n: int) -> ListNode | None:
        dummy = ListNode(-1, head)
        p_fast = dummy
        p_slow = dummy
        
        # first find the (n + 1)th node from the end by moving p_fast n + 1 steps ahead
        for i in range(n + 1):
            p_fast = p_fast.next
        
        # move both p_fast and p_slow until p_fast reaches the end
        while p_fast is not None:
            p_fast = p_fast.next
            p_slow = p_slow.next
        
        # now, p_slow points to the n + 1 node from end, p_slow->next is the node we want to remove
        p_slow.next = p_slow.next.next
        
        return dummy.next
        