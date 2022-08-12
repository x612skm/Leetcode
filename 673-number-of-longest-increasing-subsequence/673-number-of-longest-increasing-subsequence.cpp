class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        //same as of the lis here we have to count the number of same length lis
        //we hve to make two storage
        int maxlen = 1;
        int n = nums.size();
        vector<int> lis(n,1);
        vector<int> con(n,1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j] and 1+lis[j] > lis[i]){
                    lis[i] = 1+lis[j];
                    con[i] = con[j];
                }
                //if there are many lis of the same length
                else if(1+lis[j] == lis[i])
                    con[i] += con[j];
            }
            maxlen = max(maxlen,lis[i]);
        }
        
        
        int numoflis = 0;
        for(int i=0; i<n; i++){
            if(lis[i] == maxlen) //if the same length subsequcne
                numoflis += con[i];
        }
        return numoflis;
    }
};