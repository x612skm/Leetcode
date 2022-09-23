class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int>st;
        st.push(0);
        unordered_set<int>seen = {0};
        
        while(!st.empty()){
            int i = st.top();
            st.pop();
            for(int j : rooms[i]){
                if(seen.count(j) == 0){
                    st.push(j);
                    seen.insert(j);
                    if(rooms.size() == seen.size()) return true;
                }
            }
        }
        return rooms.size() == seen.size();
    }
};