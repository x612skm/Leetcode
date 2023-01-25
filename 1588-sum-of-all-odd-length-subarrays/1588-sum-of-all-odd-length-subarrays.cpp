class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            int conti = ceil((i+1)*(arr.size()-i)/2.0);
            sum += (conti * arr[i]);
        }
        return sum;
    }
};