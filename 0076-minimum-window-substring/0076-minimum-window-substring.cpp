class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp;
        for(auto c : t)
            mp[c]++;
        
        size_t start = 0, end = 0, counter = size(t), minstart = 0, minlen = INT_MAX;
        size_t sz = s.size();
        
        while(end < sz){
            if(mp[s[end]] > 0)
                counter--;
            //the count will go into negative 
            mp[s[end]]--;
            end++;
            
            while(counter == 0){
                //take the shortest length
                if(end - start < minlen){
                    minstart = start;
                    minlen = end - start;
                    
                }
                
                mp[s[start]]++;
                //cout<<s[start]<<" ";
                if(mp[s[start]] > 0)
                    counter++;
                start++;
                //cout<<start<<" ";
            }
        }
        return minlen == INT_MAX ? "" : s.substr(minstart, minlen);
    }
};