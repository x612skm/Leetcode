class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // LOGIC IS clear wherever there is 0 => -1 then count the longest sum 0
        unordered_map<int, int>mp;
        mp[0] = -1;
        
        int sum = 0; int longest_sub = 0;
        
        for(int i=0; i<(int)nums.size(); i++){
            //add -1 to the sum
            sum += nums[i] == 0 ? -1 : 1;
            //either the sum will be -1 or 0 therefor update if the sum is not found in map
            //auto it = mp.find(sum);
            if(mp.count(sum)){
                longest_sub = max(longest_sub, i-mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
        return longest_sub;
    }
};