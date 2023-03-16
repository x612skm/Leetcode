class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        #this code has a time complexity of O(n)
        #return len(nums) != len(set(nums))
        #to optimse the space complexity
        
        seen = set()
        for n in nums:
            if n in seen:
                return True
            seen.add(n)
        return False