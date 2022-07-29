class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        int begin=0, end =0, head = 0;
        int d = INT_MAX;
        
        int counter = t.size();
        
        for( auto c:t)
            map[c]++;
        
        while(end < s.size()){
            if(map[s[end++]]-->0)
                counter--;
        
        while(counter == 0){
            if(end - begin < d)
                d=end-(head = begin);
            if(map[s[begin++]]++ == 0)
                counter++;
        }
        }
        return d==INT_MAX? "" : s.substr(head,d);
    }
    
};