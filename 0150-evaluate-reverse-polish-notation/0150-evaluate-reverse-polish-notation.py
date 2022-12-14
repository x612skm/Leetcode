class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for t in tokens:
            if t not in "+-/*":
                stack.append(int(t))
            else:
                right = stack.pop()
                left = stack.pop();
                if t == "+":
                    stack.append(right + left)
                elif t == "-":
                    stack.append(left - right)
                elif t == "*":
                    stack.append(right * left)
                else:
                    stack.append(int(float(left)/right))
        return stack.pop()
        