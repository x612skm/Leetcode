class Solution:
    def isValid(self, s: str) -> bool:
        stack = ['NULL']
        m = {')':'(' , ']':'[', '}':'{'}
        for i in s:
            if i in m:
                if stack.pop() != m[i]:
                    return False
            else:
                stack.append(i)
                
        return len(stack) == 1