class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int>st;
        vector<int>ans(n,0);
        st.push(0);
        for(int i=1; i<n; i++){
            while(!st.empty() and temperatures[st.top()] < temperatures[i]){
                int curr = st.top();
                st.pop();
                ans[curr] = i - curr;
            }
            st.push(i);
        }
        return ans;
    }
};