class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0; int j = height.size()-1;
        int max_area = 0, area;
        
        while(i<j){
            area = (min(height[i],height[j])*(j-i));
            
            if(max_area < area)
                max_area = area;
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return max_area;
    }
};

