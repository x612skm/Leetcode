class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans;
        if(nums.size() <= 0) return 0;
        map<int,int> mp;
        
        for(int i=n-1; i>=0; i--){
            mp[nums[i]] = i;
        }
        
        map<int,int>::iterator it=mp.begin();
   
        int maxSize = 0;
        int first,last,maxfirst,maxlast;
        first = last = maxfirst = maxlast = it->first;
        
        for(it++; it!=mp.end(); it++){
            if(it->first == last+1){
                last = last+1;
                if(last - first > maxSize){
                    maxfirst = first;
                    maxlast = last;
                    maxSize = last - first;
                }
            }
            else
                first = last = it->first;
        }
        
        for(int i=maxfirst; i<=maxlast; i++)
            ans.push_back(i);
        
        return ans.size();
    }
};