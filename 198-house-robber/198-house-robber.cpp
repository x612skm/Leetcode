class Solution {
public:
//int static output[501][501];
int rec(vector<int>& arr, int n, vector<vector<int>>&output){
    if(n<0) return 0;
    int m = arr.size();
    
    // output = new int*[m+1];
    // for(int i=0; i<=m; i++){
    //     output[i] = new int[n+1];
    //     for(int j=0; j<=n; j++){
    //         output[i][j] = -1;
    //         }
    //     }

    if(output[m][n] != -1)
        return output[m][n];


    output[m][n] =  max(rec(arr,n-1,output), rec(arr,n-2,output) + arr[n]);
    return output[m][n];
}
int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > output( 501 , vector<int> (501, -1));
        return rec(nums,n-1,output);
    }
};