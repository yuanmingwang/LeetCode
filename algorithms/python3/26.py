class Solution:
    """
        26. Remove Duplicates from Sorted Array
        Two Pointers, slow & fast pointer

        Keep the slow pointer (`slow`) trailing behind while the fast pointer (`fast`) moves ahead to scout; whenever a unique element is found, advance `slow` by one position and write the value at `fast` to this new `slow` position.

        This ensures that the subarray `nums[0..slow]` contains only unique elements; once the `fast` pointer has traversed the entire array `nums`, the subarray `nums[0..slow]` represents the result of removing duplicates from the array.

        time O(N)
        space O(1)
    """
    def removeDuplicates(self, nums: list[int]) -> int:
        slow, fast = 0, 0
        while fast < len(nums):
            if nums[slow] != nums[fast]:
                slow += 1
                # keep  no duplicates in nums[0..slow]
                nums[slow] = nums[fast]
            fast += 1
        
        # slow points to the last element, so aarray length is slow + 1
        return slow + 1