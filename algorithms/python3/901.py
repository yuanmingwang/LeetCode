class StockSpanner:
    """ 
    901. Online Stock Span
    Monotonic Stack

    Intuition:
        For each price, find how many consecutive days up to today
        have prices less than or equal to today's price.

        Use a decreasing stack of (price, span).
        If a previous price is less than or equal to the current price,
        its entire span can be included in the current span.

    Approach:
        - Start each new price with span = 1 for the current day.
        - Pop all prices less than or equal to the current price.
        - Add each popped price's span to the current span.
        - Push (price, span) back into the stack.
        - The stack stays decreasing by price.

    Example:
        prices: 100, 80, 60, 70, 60, 75

        100 -> span = 1
        80  -> span = 1
        60  -> span = 1
        70  -> pop (60, 1), span = 2
        60  -> span = 1
        75  -> pop (60, 1) and (70, 2), span = 4

        Output: [1, 1, 1, 2, 1, 4]

    Time complexity: O(n)
        Each price is pushed and popped at most once.

    Space complexity: O(n)
        The stack can contain up to n prices.
    """

    def __init__(self):
        # Each element stores (price, span).
        self.stack = []

    def next(self, price: int) -> int:
        # Current day always counts toward its own span.
        span = 1

        # Smaller or equal prices are part of the current span.
        # Add their saved spans so we do not need to check each day again.
        while self.stack and self.stack[-1][0] <= price:
            span += self.stack.pop()[1]

        # Save the current price and its total span.
        self.stack.append((price, span))

        return span