from collections import deque
from typing import List


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        """
        Algorithm intuition:
            - since we need to maintain a local max, we can use a moonotonic non-increasing stack
            - we can push the indices to the deque (stack)
            - the first element would be the largest, then we need to keep track of the next
                largest element in window
            - so if we violate the monotonic non-increase property, we pop
            - also, if the index of the top element in window (first element) + k == i,
                then we slide the window by removing the element
        Time: O(n)
        Space: O(k)
        """
        dq = deque()
        ans = []

        for i in range(len(nums)):
            # check monotonic stack property violation
            # we don't need to store a value in window if the current index is greater than the minimum in our stack
            while dq and nums[dq[-1]] < nums[i]:
                dq.pop()

            dq.append(i)

            # if the index of largest element + k == current index
            #   then slide window by removing the max window element
            #   the second max would then take the place
            if dq[0] + k == i:
                dq.popleft()

            # append to answer only when the current index >= k - 1
            if i >= k - 1:
                ans.append(nums[dq[0]])

        return ans
