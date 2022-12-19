class Solution {
public:
    int search(vector<int>& nums, int target) {
        //rotated sorted array
        //base case if the element itself present in the middle
        //will be threee cases to be followed 
        int start = 0; int end = nums.size()-1;
        while(start <= end){
            int mid = (start + end) >> 1;
            
            if(nums[mid] == target)
                return mid;
            
            else if(nums[mid] < nums[start]){
                if(nums[mid] < target and nums[end] >= target)
                    start = mid+1;
                else
                    end = mid-1;
            }
            else if(nums[mid] > nums[end]){
                if(nums[mid] > target and nums[start] <= target)
                    end = mid-1;
                else
                    start = mid + 1;
            }
            else{
                if(target > nums[mid])
                    start = mid +1;
                else
                    end = mid-1;
            }
        }
        return -1;
    }
};