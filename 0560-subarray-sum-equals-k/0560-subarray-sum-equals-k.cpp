class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum  = 0;
        int count = 0;
        mp[count] = 1; //prefix sum technique
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int curr = sum - k;
            if(mp.count(curr))
                count += mp[curr];
            mp[sum]++;
            
        }
        return count;
    }
};