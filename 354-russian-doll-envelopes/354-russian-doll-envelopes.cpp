class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // we cannot have matrix operations as .first and .second
        int n = envelopes.size();
        vector<int>lis;
        sort(envelopes.begin(), envelopes.end(),comp);
        for(int i=0; i<n; i++){
            int ele = envelopes[i][1];
            int index = lower_bound(lis.begin(), lis.end(), ele)-lis.begin();
            cout<<index;
            if(index >= lis.size())
                lis.push_back(ele);
            else
                lis[index] = ele;
        }
        return lis.size();
    }
};