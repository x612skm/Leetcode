class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0; int end = s.size()-1;
        while(start < end){
            //swap(s[start++], s[end--]);
            //replacing the swap without using a temporary variable
            
            s[start] ^= s[end];
            s[end] ^= s[start];
            s[start] ^= s[end];
            
            ++start;
            --end;
        }
    }
};