class Solution:
    """ 
    503. Next Greater Element II
    Monotonic Stack

    Intuition:
        This is similar to 496. Next Greater Element I, but nums is circular.
        We scan the array twice from right to left so each element can also
        check elements at the beginning of the array.

    Approach:
        - Loop through 2 * n elements from right to left.
        - Use i % n to map the index back into the original array.
        - Maintain a decreasing stack of possible next greater elements.
        - Pop values smaller than or equal to the current number.
        - The stack top is the next greater element if the stack is not empty.

    Time complexity: O(n)
        Each element is pushed and popped only a constant number of times.

    Space complexity: O(n), excluding the returned array.
    """

    def nextGreaterElements(self, nums: list[int]) -> list[int]:
        n = len(nums)
        res = [-1] * n
        stack = []

        # Scan twice to simulate a circular array.
        for i in range(2 * n - 1, -1, -1):
            index = i % n
            num = nums[index]

            # Remove values that cannot be the next greater element.
            while stack and stack[-1] <= num:
                stack.pop()

            # The stack top is the nearest greater value on the right.
            res[index] = stack[-1] if stack else -1

            # Current number becomes a candidate for elements to the left.
            stack.append(num)

        return res