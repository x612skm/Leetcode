class Solution {
// private:
//     //tc = n
//     string compare(string s){
//         int count = 0;
//         string ans = "";
//         for(int i=s.size()-1; i>=0; --i){
//             if(!isalnum(s[i]))
//                 count++;
//             else{
//                 if(count == 0){
//                     ans += s[i];
//                     continue;
//                 }
//                 count--;
//             }
//         }
//         reverse(ans.begin(), ans.end()); //O(n)
//         return ans;
//     }
    //just checking the space complexity
public:
   bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1, back;
        while (true) {
            back = 0;
            while (i >= 0 && (back > 0 || S[i] == '#')) {
                back += S[i] == '#' ? 1 : -1;
                i--;
            }
            back = 0;
            while (j >= 0 && (back > 0 || T[j] == '#')) {
                back += T[j] == '#' ? 1 : -1;
                j--;
            }
            if (i >= 0 && j >= 0 && S[i] == T[j]) {
                i--;
                j--;
            } else {
                break;
            }
        }
        return i == -1 && j == -1;
    }

};