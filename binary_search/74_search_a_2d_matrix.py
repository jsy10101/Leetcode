from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        """
        Algorithm intuition:
            - we can use binary search
            - we assume the 2d array to be a 1 d array by flattening the list
            - we note that each row has n elements -> for given index, dividing by n gives the row number
            - there are n columns, which reset on every row -> for given index, taking modulo gives column number
            - once we have the row and col, we extract the element from matrix
            - then we run the binary search algorithm
        Time: O(log (m * n))
        Space: O(1)
        """
        m, n = len(matrix), len(matrix[0])

        left, right = 0, m * n - 1

        while left <= right:
            mid = (left + right) // 2

            row = mid // n
            col = mid % n

            num = matrix[row][col]

            if num == target:
                return True
            if num < target:
                left = mid + 1
            else:
                right = mid - 1

        return False
