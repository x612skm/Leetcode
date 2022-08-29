class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        unordered_map<int, bool> seen;
        
        for(int i=0; i<n; i++){
            if(seen.count(nums[i]) > 0){ //it is present
                continue;
            }
            seen[nums[i]] = true;//mark it true; //mark it 1
            output.push_back(nums[i]);
        }
        nums=output;
        return nums.size();
    }
};