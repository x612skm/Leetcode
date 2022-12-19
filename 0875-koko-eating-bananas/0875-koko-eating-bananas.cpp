class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //int sum = 0;
        int start = 1; int end = 1e9+7;
        while(start < end){
            int mid = start + end >> 1; int sum = 0;
            for(auto p : piles)
                sum += (p+mid-1)/mid;
            if(sum > h)
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }
};