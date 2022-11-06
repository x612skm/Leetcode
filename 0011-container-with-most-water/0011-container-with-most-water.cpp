class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0; int end = height.size()-1;
        int maxwater = 0;
        //maxwater = area = length * breadth
        while(start < end){
            int area = (end-start) * min(height[start], height[end]);
            maxwater = max(maxwater, area);
            if(height[start] < height[end])
                ++start;
            else
                --end;
        }
        return maxwater;
    }
};