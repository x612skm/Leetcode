class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        //first case wil be push till the closing bracket comes
        for(int i=0; i<s.size(); i++){
            if(s[i] != ']'){
                st.push(s[i]);
            }
            else{
                string curr_str = "";
                //till the [ bracket we will add the string
                while(st.top() != '['){
                    curr_str = st.top() + curr_str;
                    st.pop();
                }
                st.pop();
                string number = "";
                
                //while calculating the number we multply the number
                while(!st.empty() and isdigit(st.top())){
                    number = st.top() + number;
                    st.pop();
                }
                
                int k_time = stoi(number);
                //till the number is empty we push it again onto the stack
                while(k_time--){
                    for(int p=0; p<curr_str.size(); p++)
                        st.push(curr_str[p]);
                }
            }
        }
        //in an empty stirng we add all the things then return
        s = "";
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};