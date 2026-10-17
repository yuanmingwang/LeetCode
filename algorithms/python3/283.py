class Solution:
    """ 
        283. Move Zeroes
        Array, Two Pointers
        
        slow and fast pointer:
        1. All elements before the slow pointer are non-zeroes.
        2. All elements between the fast and slow pointer are zeroes.

        when we encounter a non-zero element, we need to swap elements pointed by fast and slow pointer, then advance both pointers. If it's zero element, we just advance fast pointer.

        time O(n)
        space O(1)
    """
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        slow = 0
        fast = 0
        while fast < len(nums):
            ## swap slow and fast
            if nums[fast] != 0:
                nums[slow], nums[fast] = nums[fast], nums[slow]
                slow += 1
            fast += 1