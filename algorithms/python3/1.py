class Solution:
    """ 
        1. Two Sum
        Hash Table

        time O(N)
        space O(N)
    """
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashtable = {} # key = num, v = index of num in nums
        for i in range(len(nums)):
            num = nums[i]
            need = target - num # number we need to get target
            if need in hashtable:
                return [hashtable[need], i]
            hashtable[num] = i
        return []