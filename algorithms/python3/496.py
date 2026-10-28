class Solution:
    """ 
    496. Next Greater Element I
    Monotonic Stack

    Intuition:
        For each number in nums1, we need to find the first greater number
        to its right in nums2 where nums1 is a subset of nums2.

        Instead of searching to the right for every number, we process nums2
        from right to left and use a monotonic decreasing stack to keep only
        useful candidates for the next greater element.

    Approach:
        - Use a dictionary to map each number in nums2 to its next greater element.
        - Traverse nums2 from right to left.
        - Maintain a decreasing stack:
            - Remove values that are smaller than or equal to the current number,
            because they cannot be the next greater element.
            - After removing them, the top of the stack is the closest greater
            element on the right.
            - Add the current number to the stack so it can be a candidate for
            numbers further to the left.
        - Use the dictionary to find the answer for each number in nums1.

    Time complexity: O(m + n)
        m is the length of nums2
        n is the length of nums1

    Space complexity: O(m), excluding the returned array.
    """

    def nextGreaterElement(self, nums1: list[int], nums2: list[int]) -> list[int]:
        stack = []
        nextGreater = {}

        # Go from right to left so the stack contains numbers
        # that appear to the right of the current number.
        for num in reversed(nums2):

            # Remove smaller or equal numbers.
            # They cannot be the next greater element for num,
            # and num will also block them for numbers further to the left.
            while stack and stack[-1] <= num:
                stack.pop()

            # If the stack is not empty, its top is the nearest
            # greater number on the right.
            nextGreater[num] = stack[-1] if stack else -1

            # Add the current number as a candidate for
            # numbers that will be processed later.
            stack.append(num)

        return [nextGreater[num] for num in nums1]