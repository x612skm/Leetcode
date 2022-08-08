class MyCalendar {
public:
    //we created a ordered map here 
    map<int,int>mp;
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        auto it = mp.upper_bound(start);
        //we check the overflow
       
        if( it != mp.end()){
            if(it->first < end)
                return false;
        }
        if(it != mp.begin()){
            if(prev(it)->second > start) return false;
        }
        mp[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */