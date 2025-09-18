def ArrayAddition(arr):
    """
    Algorithm Approach:
    - Find the largest number in the array (this becomes our target sum)
    - Use backtracking to check if any combination of remaining numbers can sum to target
    - This is a classic "Subset Sum" problem variant

    Approach Analysis:
    1. Brute Force: Check all 2^n subsets - O(2^n) time
    2. Dynamic Programming: O(n * sum_range) - good when sum range is small
    3. Backtracking with pruning: O(2^n) worst case but faster in practice

    Choosing backtracking for clarity and interview friendliness

    Time: O(2^n) worst case, but pruning makes it faster in practice
    Space: O(n) for recursion stack
    """

    if len(arr) <= 1:
        return "false"

    # Find the largest number (our target)
    target = max(arr)

    # Remove the largest number, use remaining for subset sum
    remaining = [x for x in arr if x != target]

    def can_make_sum(nums, target_sum, index=0):
        """
        Backtracking helper function
        Returns True if we can make target_sum using nums[index:]
        """
        # Base case: found exact sum
        if target_sum == 0:
            return True

        # Base case: no more numbers to try
        if index >= len(nums):
            return False

        # Pruning: if target_sum is negative and all remaining nums are positive
        if target_sum < 0 and all(nums[i] >= 0 for i in range(index, len(nums))):
            return False

        # Try including current number
        if can_make_sum(nums, target_sum - nums[index], index + 1):
            return True

        # Try excluding current number
        if can_make_sum(nums, target_sum, index + 1):
            return True

        return False

    # Check if we can make the target sum
    result = can_make_sum(remaining, target)
    return "true" if result else "false"


def ArrayAdditionOptimized(arr):
    """
    Alternative DP solution for when sum range is reasonable
    More efficient for larger arrays with smaller sum ranges
    Time: O(n^2)
    Space: O(n)
    """
    if len(arr) <= 1:
        return "false"

    target = max(arr)
    remaining = [x for x in arr if x != target]

    # Calculate possible sum range
    pos_sum = sum(x for x in remaining if x > 0)
    neg_sum = sum(x for x in remaining if x < 0)

    # Quick bounds check
    if target > pos_sum or target < neg_sum:
        return "false"

    # DP approach with offset for negative numbers
    offset = -neg_sum
    dp_size = pos_sum - neg_sum + 1
    dp = [False] * dp_size
    dp[offset] = True  # Sum of 0 is possible with empty set

    for num in remaining:
        # Process in reverse to avoid using same number twice
        for i in range(dp_size - 1, -1, -1):
            if dp[i]:
                new_sum_index = i + num
                if 0 <= new_sum_index < dp_size:
                    dp[new_sum_index] = True

    target_index = target + offset
    return "true" if 0 <= target_index < dp_size and dp[target_index] else "false"


# Test with provided examples
print(ArrayAddition([5, 7, 16, 1, 2]))  # Expected: false (5+7+1+2=15 ≠ 16)
print(ArrayAddition([3, 5, -1, 8, 12]))  # Expected: true (8+5-1=12 ✓)

# Keep this function call here
print(ArrayAddition([5, 7, 16, 1, 2]))
