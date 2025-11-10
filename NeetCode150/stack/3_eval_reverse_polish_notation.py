from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        """
        Algorithm intuition:
            - maintain a stack
            - add number token to stack
            - pop from stack if we see and operend
            - perform arithmatic and push the res back to stack
            - in the end stack should just have one element containing ans
            - we need a way to determine if we have a operand or an operator
                - define a str with valid operands
                - check if current token operand
                - if yes -> perform operation by converting operator
                - if no -> it must be an operand -> convert to int and push it to stack
        Time: O(n)
        Space: O(n)
        """
        stack = []
        operands = "+-*/"

        for token in tokens:
            if token in operands:
                # perform operation
                num2 = stack.pop()
                num1 = stack.pop()

                if token == "+":
                    res = num1 + num2
                elif token == "-":
                    res = num1 - num2
                elif token == "/":
                    res = int(num1 / num2)
                else:
                    res = num1 * num2

                stack.append(res)
            else:
                num = int(token)
                stack.append(num)

        return stack[-1]
