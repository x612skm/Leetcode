class Solution {
public:
    int scoreOfParentheses(string s) {
        //using stack
        stack<int> st;
        int cur = 0;
        for(auto i : s){
            if(i == '('){
                st.push(cur);
                cur = 0;
            }
            else{
                cur += st.top() + max(cur , 1);
                st.pop();
            }
        }
        return cur;
    
    }
};