# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    """
        160. Intersection of Two Linked Lists
        Linked List, Two Pointers


        The key to solving this problem is to make p1 and p2 reach the intersecting node c1 simultaneously through some method.

        So, we can let p1 traverse through list A and then start traversing list B, while p2 traverses through list B and then starts traversing list A. 
        This approach effectively "logically" connects the two linked lists.

        By doing this, p1 and p2 can enter the common section simultaneously, reaching the intersecting node c1

        time O(n)
        space O(1)
    """
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        p_a = headA
        p_b = headB
        
        while p_a != p_b:
            p_a = headB if p_a is None else p_a.next
            p_b = headA if p_b is None else p_b.next
        
        return p_a