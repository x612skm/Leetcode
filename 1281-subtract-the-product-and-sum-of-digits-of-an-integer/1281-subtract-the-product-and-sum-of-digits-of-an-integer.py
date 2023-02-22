class Solution:
    
    def subtractProductAndSum(self, n: int) -> int:
        product = 1
        sums = 0
        while(n!=0):
            product = product * (n % 10)
            sums = sums + (n % 10)
            n = n//10
        
        
        
        
        return product - sums