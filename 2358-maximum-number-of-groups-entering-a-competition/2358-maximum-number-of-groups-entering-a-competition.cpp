class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        //using the binary search
        int left = 1; int right = 446;
        int n = grades.size();
        
        while(left < right){
            int k = (left + right + 1 )/2;
            
            if( k*(k+1) / 2 <= n ){
                left = k;
            }
            else
                right = k-1;
        }
        return left;
    }
};

