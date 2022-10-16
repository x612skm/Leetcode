class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //using kadane's algorithm also a dp soln
        int max_end = 0; int max_till_now = INT_MIN;
        for(auto i : nums){
            max_end = max(i, max_end+i);
            max_till_now = max(max_end, max_till_now);
        }
        return max_till_now;
    }
};