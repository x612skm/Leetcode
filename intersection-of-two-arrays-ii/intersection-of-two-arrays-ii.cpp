class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        int n = nums1.size(); int m = nums2.size();
        
        
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++)
            mp[nums1[i]]++;
        
        for(int i=0; i<m; i++){
            if(mp.count(nums2[i])){
                output.push_back(nums2[i]);
                if(mp[nums2[i]] == 1)
                    mp.erase(nums2[i]);
                else
                    mp[nums2[i]]--;
            }
        }
        return output;
    }
};