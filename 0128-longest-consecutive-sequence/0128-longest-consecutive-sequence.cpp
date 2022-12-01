class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int longest = 0;
        
        for(auto it:nums){
            if(!st.count(it-1)){
                int next = 1;
                while(st.count(it+next))
                    next++;
                longest = max(next, longest);
            }
        }
        return longest;
    }
};