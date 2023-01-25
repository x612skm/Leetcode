class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        unordered_map<int, int>mp;
        
        for(int n:nums2){
            while(s.size() and s.top() < n){
                mp[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int>ans;
        for(auto n : nums1){
            ans.push_back(mp.count(n) ? mp[n] : -1);
            
        }
        return ans;
    }
};