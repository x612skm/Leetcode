class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(is_sorted(nums.begin(), nums.end()))
            return true;
        if(is_sorted(nums.begin(), nums.end(), greater<>()))
            return true;
        return false;
    }
};