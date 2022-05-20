class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int start =0; 
        //start => mid
        int mid = 0; int end = n-1;
        while(mid <= end){
            if(nums[mid] == 1)
                mid++;
            
            else if(nums[mid] == 0){
                swap(nums[mid], nums[start]);
                start++;
                mid++;
                //cout<<nums[mid];
            }
            
            else
            {
                swap(nums[mid], nums[end]);
                end--;
                
            }
        }
    }
};