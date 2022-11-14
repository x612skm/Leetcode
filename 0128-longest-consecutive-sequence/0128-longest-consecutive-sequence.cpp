class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        int longest = 0;
        for(int i=0; i<nums.size(); i++){
            //check if the sequence is starting or not
            //if the previous element is not present in the set it may be starting at this
            if(!s.count(nums[i]-1)){
                int next = 1;
                while(s.count(nums[i]+next))
                    next++;
                longest = max(longest, next);
            }
        }
        return longest;
    }
};