class Solution {
public:
    int bS(vector<int>& nums, int target, int start, int end){
        int n = nums.size();
        //start = 0, end = n-1;
        
        int mid = start + (end - start)/2;
        
        while(start <= end){
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid]>target)
                return bS(nums, target, start, mid-1);    
            return bS(nums, target, mid+1, end);
            
        
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        //start = 0, end = n-1;
        
        //int mid = start + (end - start)/2;

        return bS(nums,target, 0, n-1);
    }
};