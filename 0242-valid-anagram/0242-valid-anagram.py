class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict = {}
        for item in s:
            if item not in dict:
                dict[item] = 1 #put that into dict
            else:
                dict[item] += 1 #increase the counter
        for item in t:
            if item not in dict:
                return False
            else:
                dict[item] -= 1
                
        for val in dict.values():
            if val != 0:
                return False
            
        return True
            