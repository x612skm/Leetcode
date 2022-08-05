class Solution {
public:
    int solverFunc(vector<int>& nums, int val){
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=val) count++;
        }
        return count;
    }
    int specialArray(vector<int>& nums) {
        int left = 0; int right = nums.size();
        while(left <= right){
            int mid = left + (right-left)/2;
            int counter = solverFunc(nums,mid);
            
            if(counter == mid) return counter;
            
            if(counter>mid) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
};