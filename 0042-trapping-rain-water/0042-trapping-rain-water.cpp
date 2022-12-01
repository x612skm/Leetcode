class Solution {
public:
    int trap(vector<int>& height) {
        //marking the left and the right
        int left = 1; int right = height.size()-2;
        //makeing two pointers 
        int maxleft = height[0]; int maxright = height[height.size()-1];
        int ans = 0;
        //left == right because we have to caluclate the last cell also
        while(left <= right){
            if(maxleft < maxright){
                if(maxleft < height[left])
                    maxleft = height[left];
                else //if it is less then calculate the difference 
                    ans += maxleft - height[left];//the diffrence is the req result
                left++;//if left < right
            }
            else{
                if(maxright < height[right])
                    maxright = height[right];
                else
                    ans+= maxright - height[right];
                right--;//if right less than left
            }
        }
        return ans;
    }
};