class Solution:
    """ 
        344. Reverse String
        Two Pointers

        time O(N)
        space O(1)
    """
    def reverseString(self, s: list[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        left = 0
        right = len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1