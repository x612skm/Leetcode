class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        for i,j in enumerate(nums):
            r = target-j
            if r in dict:
                return [dict[r], i]
            dict[j] = i 
            