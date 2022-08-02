class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        //mathematical approach
        int size = grades.size();
        int ans = 0;
        int x = 1;
        
        while(x<=size){
            ans++;
            size -= x;
            x++;
        }
        return ans;
    }
};

