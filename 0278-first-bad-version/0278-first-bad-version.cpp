// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

//this is a binary search on answer based problem you just have to use the api given
class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1; int end = n; int ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isBadVersion(mid)){
                ans = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return ans;
    }
};