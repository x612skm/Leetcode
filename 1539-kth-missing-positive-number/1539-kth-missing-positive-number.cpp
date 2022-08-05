class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //writing the basic binary search format
        int left = 0; 
        int right = arr.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2; // to avoid overflow
            //for every index we have the i+1 format (mid+1)
            //in this format 
            //acc to maths arr[mid] = 1+mid;
            if(arr[mid] - (1+mid) < k)
                left = mid+1;
            else
                right=mid-1;
        }
        return left+k;
    }
};