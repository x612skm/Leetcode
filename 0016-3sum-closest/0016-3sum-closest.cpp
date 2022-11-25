class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int>v(nums.begin(), nums.end());
            int n = 0;
            int sum = 0;
            int ans = 0;
            //variation of triplet sum
            sort(v.begin(), v.end());
            
            //less than 3 elements then return their sum
            while(v.size() <= 3){
                return accumulate(v.begin(), v.end(), 0);
            }
            n = v.size(); //when it is not less than 3
            
            ans = v[0] + v[1] + v[2];
            
            for(int i=0; i<n-2; i++){
                int j = i+1;
                int k = n-1; //targeting the last element
                while(j<k){
                    sum = v[i] + v[j] + v[k];
                    if(abs(target-ans) > abs(target-sum)){
                        ans = sum;
                        if(ans == target)
                            return ans;
                    }
                    (sum > target) ? k-- : j++;
                }
                
            }
            
        
        return ans;
    }
};