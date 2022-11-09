class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //using the stl
        next_permutation(nums.begin(), nums.end());
    }
};