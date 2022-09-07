class MyStack {
public:
    //we have to make lifo principle from fifo
    queue<int>input;
    
    MyStack() {
        //no value as dynamic constructur    
    }
    
    void push(int x) {
        input.push(x);
        for(int i=0; i< input.size()-1; i++){
            input.push(input.front());//first in last out or last in first out
            //last person in the line is the first in the stack
            input.pop();
        }
    }
    
    int pop() {
         //first in first out
        int result = top();
        input.pop();
        return result;
        
    }
    
    int top() {
        return input.front();
    }
    
    bool empty() {
        return input.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */