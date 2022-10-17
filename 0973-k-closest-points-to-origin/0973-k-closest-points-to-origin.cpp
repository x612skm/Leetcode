class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //first solution comes to mind seeing that k is the heap
        //taking the max heap as to take the min heap we have to take all the elements
        //ans should be in 2D vector
        vector<vector<int>> ans(k);
        //making a priority queue of vector
        priority_queue<vector<int>> maxheap;
        //making the reading inside the priority quueue
        //lets not take the square root
        //instead we take the total as
        for(auto& p:points){
            int x = p[0]; int y = p[1];
            int total = x * x + y * y;
            maxheap.push({total,x,y});
            //we only need the elements to the size of k rest we can pop out
            //here maxheap comes into play it sorts according to the lower ones asceding
            if(maxheap.size() > k)
                maxheap.pop();
        }
        for(int i=0; i<k; i++){
            vector<int>top_in_queue = maxheap.top();
            maxheap.pop();
            ans[i] = {top_in_queue[1], top_in_queue[2]};
        }
        return ans;
    }
};