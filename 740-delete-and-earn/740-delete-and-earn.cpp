class Solution {
public:
    int t[20001];
    int solve(vector<int>& arr, int i){
        if(i>=arr.size())
            return 0;
        
        if(t[i] != -1)
            return t[i];
        
        int curr_val = arr[i];
        int curr_sum = arr[i];
        int index = i + 1;
        
        while(index < arr.size() && arr[index] == curr_val){
            curr_sum += arr[i];
            index++;
        }
        
        while(index<arr.size() && arr[index] == curr_val + 1) index++;
        
        return t[i] = max(curr_sum + solve(arr,index), solve(arr, i+1));
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        sort(nums.begin(), nums.end());
        return solve(nums,0);
        
    }
};