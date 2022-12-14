class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //we have to output the temperatures vector
        int n = temperatures.size();
        vector<int>ans(n, 0);
        
        stack<int>st;
        st.push(0);
        for(int i=1; i<n; i++){
            while(!st.empty() and temperatures[st.top()] < temperatures[i]){
                int curr = st.top();
                st.pop();
                ans[curr] = i- curr;
            }
            st.push(i);
        }
        return ans;
    }
};