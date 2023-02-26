class Solution:
    def sum(self, n:int) -> int:
        s = 0
        while(n):
            t = n % 10
            s+= t*t
            n = n//10
        return s
    
    def isHappy(self, n: int) -> bool:
        # l1 = n
        # l2 = self.sum(n)
        # while (l1 != l2):
        #     l1 = self.sum(l1)
        #     l2 = self.sum(self.sum(l1))
        # return l1 == 1
        #This is more optimised than the floyed cycle detection algotihm
        #make a set
        seen = set()
        while n not in seen:
            seen.add(n)
            n = self.sum(n)
            if n == 1:
                return True
        return False