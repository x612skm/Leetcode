class MinStack {
    class Node{   
    public:
    int val;
    int min;
    Node* next;
    
    Node(int val, int min, Node* next){
        this->val = val;
        this->min = min;
        this->next = next;
    }
};
Node* head;
public:
    MinStack() {
        head = nullptr;
    }
    void push(int val) {
        if(head == nullptr)
            head = new Node(val, val, nullptr);
        else{
            head = new Node(val, min(val, head->min),head);
            //head= new Node(val, min(val, head->mini), head);
        }
    }
    
    void pop() {
        head = head->next;    
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */