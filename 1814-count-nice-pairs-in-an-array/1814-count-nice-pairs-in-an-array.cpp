class Solution {
public:
    int rev(int a) {
        int b = 0;
        while (a > 0) {
            b = b * 10 + (a % 10);
            a /= 10;
        }
        return b;
    }
    
    int countNicePairs(vector<int>& nums) {
        long count = 0; int mod = 1e9+7;
        unordered_map<int,int>mp;
        for(auto& i:nums){
            count = (count + mp[i-rev(i)]++) % mod;
        }
        return count;
    }
};