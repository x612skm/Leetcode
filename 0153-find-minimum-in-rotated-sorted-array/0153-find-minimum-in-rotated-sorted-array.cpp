class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0; int end = nums.size()-1;
        
        while(start < end){
            //base case
            if(nums[start] < nums[end])
                return nums[start];
            //binary search
            int mid = start + end >> 1;
            if(nums[mid] >= nums[start])
                start = mid + 1;
            else
                end = mid;
        }
        return nums[start];
    }
};