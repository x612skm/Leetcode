#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;

class Solution {
private:
    int maxheight(int length, vector<int>& cutting){
        sort(cutting.begin(), cutting.end());
        
        int newHeight = cutting.size();
        int maxHeight = max(length - cutting[newHeight-1], cutting[0]);
        
        for(int i=1; i<newHeight; i++){
            maxHeight = max(maxHeight, cutting[i]-cutting[i-1]);
        }
        return maxHeight;
    }
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return (int)((long) maxheight(h, horizontalCuts) * maxheight(w, verticalCuts) % mod);
    }
};