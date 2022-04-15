class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = 1e9;
        int count;
        
        while(left < right){
            count  = 0;
            int mid = left + (right - left) / 2;
            
            for(int i : nums)
                count += (i - 1)/mid;
                if(count > maxOperations)
                    left = mid + 1;
                else    
                    right = mid;
            
        }
        return left;
    }
};