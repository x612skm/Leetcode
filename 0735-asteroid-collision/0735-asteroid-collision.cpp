class Solution {
public:
    //marking asteroid as ast in the signature
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;
        for(int i=0; i<ast.size(); i++){
            if(st.empty() or ast[i] > 0)
                st.push(ast[i]);
            else{
                //case 1 when the abs(ast[i]) is greater or equal to 
                while(!st.empty() and st.top() > 0 and st.top() < abs(ast[i]))
                    st.pop();
                if(!st.empty() and st.top() == abs(ast[i]))
                    st.pop();
                else 
                    if(st.empty() or st.top() < 0)
                        st.push(ast[i]);
            }
        }
        vector<int>ans(st.size());
        for(int i=st.size()-1; i>=0; i--){
            ans[i] = st.top();
            st.pop();
        }
        
        return ans;
    }
};