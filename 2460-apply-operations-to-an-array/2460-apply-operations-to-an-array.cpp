class Solution {
private:
    void push_zeros_to_end(std::vector<int>& arr){
            std::stable_partition(arr.begin(),
                arr.end(),
                    [](int n) { return n != 0; });
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