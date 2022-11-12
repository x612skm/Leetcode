class Solution {
private:
    void push_zeros_to_end(vector<int>&nums){
        int k = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[k]);
                k++;
            }
        }
    }
public:
    vector<int> applyOperations(vector<int>& nums) {
       
        int n = nums.size();
        vector<int>a;
        
        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
           }
        }
        
        push_zeros_to_end(nums);
        return nums;
    }
};