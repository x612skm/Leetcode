class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        //last task of type a 
        //completd on last[a] day
        
        unordered_map<long long, long long> last;
        long long res = 0;
        
        for(auto i : tasks){
            if(last.count(i))//if the task found in the map
                last[i] = res = max(res, last[i]+space) + 1;
            else
                last[i] = ++res;
        }
        return res;
    }
};