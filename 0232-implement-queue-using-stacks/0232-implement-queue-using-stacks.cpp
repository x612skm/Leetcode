class MyQueue {
public:
    stack<int>st,op;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        int ans = peek();
        op.pop();
        return ans;
    }
    
    int peek() {
        if(op.empty()){
            while(st.size()){
                op.push(st.top());
                st.pop();
            }
        }
        return op.top();
    }
    
    bool empty() {
        return st.empty() and op.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */