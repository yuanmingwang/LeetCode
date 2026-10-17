class Solution:
    """ 
        27. Remove Element
        Array, Two Pointers
        slow and fast pointer:

        If fast encounters an element with the value val, it skips it. 
        Otherwise, it assigns the value to the slow pointer and moves the slow pointer forward.

        time O(n)
        space O(1)
    """
    def removeElement(self, nums: list[int], val: int) -> int:
        slow = 0
        fast = 0
        while fast < len(nums):
            ## ensuring that nums[0..slow-1] does not contain elements with the value val.
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        ## final length of the result array is slow.
        return slow