class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        for(auto it:s){
            if(it == '(' or it == '[' or it == '{')
                st.push(it);
            
            else{
                if(st.empty() or (st.top() == '(' and it != ')') or (st.top() == '[' and it != ']') or (st.top() == '{' and it != '}'))
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};