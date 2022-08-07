class Solution {
public:
    int m, n; //m for thr rows and n for the cols
    //lets make the recurrance relation
    int searcher(vector<vector<int>>& matrix, int x){
        int col = matrix[0].size()-1; //starting from the last row
        int count = 0;
        
        for(int row = 0; row < matrix.size(); row++){
            while(col >= 0 && matrix[row][col] > x) col--;
            count += (col+1);  
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size();  
        n = matrix[0].size();
        int start = matrix[0][0];
        int end = matrix[m-1][n-1];
        int ans = -1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            
            //now comes the recurrance condition
            if(searcher(matrix,mid) >= k){
                ans = mid;
                end = mid -1;
            }
            else
                start = mid+1;
            
        }
        return ans;
    }
};