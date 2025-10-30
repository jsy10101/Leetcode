import sys


def solution(A):
    sys.stderr.write(
        "Tip: Use sys.stderr.write() to write debug messages on the output tab.\n"
    )
    """
  Algorithm intuition:
    - initial intuition: compute maximums (prefix) max
    - result will be sorted only if max(left) <= min(right)
    - design prob: prefix/suffix
    - 10 min spent on intuition -> coding in IDE
  Time: O(n)
  Space: O(n)
  """
    n = len(A)
    prefixMax = [0] * n
    prefixMax[0] = A[0]

    for i in range(1, n):
        prefixMax[i] = max(prefixMax[i - 1], A[i])

    suffixMin = [0] * n
    suffixMin[n - 1] = A[n - 1]

    for i in range(n - 2, -1, -1):
        suffixMin[i] = min(suffixMin[i + 1], A[i])

    splits = 0
    for i in range(n - 1):
        leftMax = prefixMax[i]
        rightMin = suffixMin[i + 1]

        if leftMax <= rightMin:
            splits += 1

    return splits


if __name__ == "__main__":
    A = [3, 2, 10, 9]
    print(solution(A))  # Expected output: 1

    A1 = [1, 3, 2, 4]
    print(solution(A1))  # Expected output: 2

    A2 = [5, 5, 5]
    print(solution(A2))  # Expected output: 2
