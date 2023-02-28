#Runtime: 23 ms, faster than 98.03% of Python3 online submissions for Check if One String Swap Can Make #Strings Equal.
#Time Complexity : O(n) where n is the number of input strings.
#Space Complexity : O(1) we are not using any separate space
class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        #first I have to check for the length of the both strings
        if len(s1) != len(s2):
            return False
        #lets check for the differnce 
        diffs = []
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                diffs.append(i)
                if len(diffs) > 2:
                    return False #because we are restricted to check for one string
                
        if len(diffs) == 0:
            return True
        elif len(diffs) == 2:
            i,j = diffs
            if s1[i] == s2[j] and s1[j] == s2[i]:
                return True
            
        return False