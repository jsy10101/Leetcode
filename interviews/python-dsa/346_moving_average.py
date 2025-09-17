from collections import deque


class MovingAverage:

    def __init__(self, size: int):
        self.queue = deque()
        self.window_size = size
        self.curr_sum = 0

    def next(self, val: int) -> float:
        """
        Algorithm intuition:
            - maintain a variable for holding current sum
            - declare a queue (deque)
            - whenever queue length becomes greater than window size
                - popleft from queue
                - subtract the popped element
        Time: O(n)
        Space: O(n)
        """
        self.queue.append(val)

        n = len(self.queue)

        if n > self.window_size:
            self.curr_sum -= self.queue.popleft()
            n -= 1

        self.curr_sum += self.queue[-1]

        return self.curr_sum / n


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
