class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        #making a stack and a map
        s = []
        mp = {}
        #for checking the nums2
        for n in nums2:
            while s and s[-1] < n: #while s is not empty and the top of s < n
                mp[s[-1]] = n
                s.pop()
            s.append(n)
        ans = []
        for n in nums1:
            ans.append(mp[n] if n in mp else -1)
        return ans

        