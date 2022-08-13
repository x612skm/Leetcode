class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
int maxEnvelopes(vector<vector<int>>& envelopes) {
        int N = envelopes.size();
        vector<int> candidates;
        sort(envelopes.begin(), envelopes.end(), cmp);
        for (int i = 0; i < N; i++) {
            int lo = 0, hi = candidates.size() - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo)/2;
                if (envelopes[i][1] > envelopes[candidates[mid]][1])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            if (lo == candidates.size())
                candidates.push_back(i);
            else
                candidates[lo] = i;
        }
        return candidates.size();
    }
};