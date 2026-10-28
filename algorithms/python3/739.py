class Solution:
    """ 
    739. Daily Temperatures
    Monotonic Stack

    Intuition:
        This is similar to 496. Next Greater Element I.
        For each day, we want to find the next day with a warmer temperature.

        We scan from right to left and use a decreasing stack to keep
        possible warmer days.

    Approach:
        - Store indices in the stack instead of temperatures.
        - Pop days with temperatures less than or equal to the current day.
        - After popping, the stack top is the next warmer day.
        - The answer is the difference between the two indices.

    Time complexity: O(n)
        Each index is pushed and popped at most once.

    Space complexity: O(n), excluding the returned array.
    """

    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        n = len(temperatures)
        res = [0] * n
        stack = []

        # Scan from right to left.
        # Stack stores indices of possible warmer days.
        for i in range(n - 1, -1, -1):

            # Remove days that are not warmer than the current day.
            while stack and temperatures[stack[-1]] <= temperatures[i]:
                stack.pop()

            # Stack top is the index of the next warmer day.
            # Since i is the current day index, their difference is
            # how many days we need to wait.
            res[i] = stack[-1] - i if stack else 0

            # Current day becomes a candidate for earlier days.
            stack.append(i)

        return res