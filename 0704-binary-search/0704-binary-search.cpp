class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        size_t start = 0; size_t end = n;
        while(start < end){
            size_t mid = start + end >> 1;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                start = mid + 1;
            else
                end = mid;
        }
        return -1;
    }
};