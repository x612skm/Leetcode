class MedianFinder {
private:
    priority_queue<int>firstpq;
    priority_queue<int, vector<int>, greater<int>> secondpq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //if belonging to the second half
        if(firstpq.empty() or (firstpq.top() > num))
            firstpq.push(num);
        else
            secondpq.push(num);
        
        if(firstpq.size() > (secondpq.size()+1)){
            secondpq.push(firstpq.top());
            firstpq.pop();
        }
        else if(firstpq.size()+1 < secondpq.size()){
            firstpq.push(secondpq.top());
            secondpq.pop();
        }
    }
    
    double findMedian() {
        if(firstpq.size() == secondpq.size())
            return firstpq.empty() ? 0 : ((firstpq.top() + secondpq.top())/2.0);
        else
            return (firstpq.size() > secondpq.size()) ? firstpq.top() : secondpq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */