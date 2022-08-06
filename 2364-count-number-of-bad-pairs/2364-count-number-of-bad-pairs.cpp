class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       //doing the optimised solutions as getting
        //Tle in brute force cpp
        long count = 0;
        //we create a map to store all the items 
        unordered_map<int,int>mp;
        //going by the concept
        //total = invalid + valid
        //given equation can also be written as
        // j-nums[j] != i-nums[i]
        
        for(int i=0; i<nums.size(); i++){
            count+= i - mp[i-nums[i]];
            mp[i-nums[i]]++;
        }
        return count;
    }
};