class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //using deque
        vector<int>ans;
        deque<int>dq;
        
        //making a window and making the max element to the last
        
        for(int i=0; i<nums.size(); i++){
            //handelling the edge case
            if(!dq.empty() and dq.front() == i-k)
                dq.pop_front();
            //this is the main line of code
            while(!dq.empty() and nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};