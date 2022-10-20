class Solution {
public:
    int search(vector<int>& nums, int target) {
        //solving it in o(log n) means to divide it into two
        int left = 0; int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            //checking the 3 condiotns
            
            if(target == nums[mid])
                return mid;
            
            else if(nums[mid] > nums[right]){
                //we will search the left side
                if(nums[mid] > target and nums[left]<=target)
                    right = mid -1;
                else
                    left = mid + 1;
            }
            else if(nums[mid] < nums[left]){
                //search in the right side
                if(nums[mid] < target and nums[right] >= target)
                    left = mid +1;
                else
                    right = mid-1;
            }
            else
                if(target > nums[mid])
                    left = mid + 1;
                else
                    right = mid -1;
        }
        return -1;
    }
};