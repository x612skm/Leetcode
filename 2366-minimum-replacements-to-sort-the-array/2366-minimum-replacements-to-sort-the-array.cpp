class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0, previous = nums[nums.size()-1];
        long long numberoftimeToDivide;
        for(int i=nums.size()-2; i>=0; i--){
            numberoftimeToDivide = nums[i]/previous;
            if(nums[i] % previous != 0){
                numberoftimeToDivide++;
                previous = nums[i]/numberoftimeToDivide;
            }
            ans += numberoftimeToDivide-1;
        }
        return ans;
    }
};