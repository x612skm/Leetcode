class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int>mp;
        int counter = t.size();
        int begin = 0; int end = 0, d = INT_MAX, head = 0;
        
        for(auto c:t){
            mp[c]++;
        }
        
        while(end < s.size()){
            if(mp[s[end++]]-- > 0){
                counter--;
            }
            while(counter == 0){
                if(end - begin < d)
                    d= end - (head = begin);
                
                if(mp[s[begin++]]++ == 0)
                    counter++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head,d);
    }
};