class Solution:
    """ 
        167. Two Sum II - Input Array Is Sorted
        Two Pointers

        One pointer starts at the beginning (0), and the other starts at the end (len(numbers) - 1):
        Now we check the sum of the two numbers:
            If the sum is too small, we move left right to get a larger value.
            If the sum is too large, we move right left to get a smaller value.
            If the sum equals the target, we've found our answer.
        This works because the array is sorted.

        time O(N)
        space O(1)
    """
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        left = 0
        right = len(numbers) - 1
        while left < right:
            sum = numbers[left] + numbers[right]
            if sum < target:
                left += 1
            elif sum > target:
                right -= 1
            elif sum == target:
                return [left + 1, right + 1]
        return [-1, -1] # no sol