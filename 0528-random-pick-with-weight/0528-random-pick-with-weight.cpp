class Solution {
public:
    vector<int>v;
    Solution(vector<int>& w) {
        for(int i=0; i<w.size(); i++){
            if(v.empty())
                v.push_back(w[i]);
            else
                v.push_back(w[i] + v.back());
        }
    }
    
    int pickIndex() {
        int idx = v.back();
        int target = rand() % idx+1;
        auto it = lower_bound(v.begin(), v.end(), target)-v.begin();
        return it;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */