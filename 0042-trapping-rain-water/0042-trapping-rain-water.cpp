class Solution {
public:
    //kabhi kabhi man nahi karega magar hausla nahi harna hai
    //karte rehna hai
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 1; int right = n-2;
        int ans = 0;
        int maxleft = height[0]; int maxright = height[n-1];
        
        while(left <= right){
            //till then the right is not equal to the left
            if(maxleft < maxright){
                if(maxleft < height[left])
                    maxleft = height[left];
                else
                    ans += maxleft - height[left];
                left++;
            }
            else{
                if(maxright < height[right])
                    maxright = height[right];
                else
                    ans+=maxright - height[right];
                --right;
            }
        }
        return ans;
    }
};