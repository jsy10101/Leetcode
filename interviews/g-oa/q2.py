import sys


def solution(A):
    sys.stderr.write(
        "Tip: Use sys.stderr.write() to write debug messages on the output tab.\n"
    )
    """
  Algorithm intuition:
    - inital intuition: calculate the sum (first pass)
    - second pass: multiply each element by -1 and check if abs(sum - (2 * elem)) = abs(distance from 0) is closer to 0
    - case 1: [1, 3, 2, 5] -> 11 sum -> sums with one element * -1 -> (9, 5, 7, 1) -> return 1
    - case 2: [4, -3, 5, -7] -> -1 sum -> sums with one element * -1 -> (-9, 5, -11, 13) -> return -1
    - 10 min spent on intuition -> coding in IDE
  Time: O(n)
  Space: O(1)
  """

    totalSum = 0
    for num in A:
        totalSum += num

    minSum = abs(totalSum)

    for num in A:
        currSum = abs(totalSum - (2 * num))
        minSum = min(minSum, currSum)

    return minSum


if __name__ == "__main__":
    A = [1, 3, 2, 5]
    print(solution(A))  # Expected output: 1

    A1 = [-4, 0, -3, -3]
    print(solution(A1))  # Expected output: 2

    A2 = [-15, 18, -1, -1, 10, -22]
    print(solution(A2))  # Expected output: 9
