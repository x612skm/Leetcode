```
class Solution {
public:
int trap(vector<int>& height) {
int left = 1; int right = height.size()-2;
int maxleft = height[0]; int maxright = height[height.size()-1];
int ans = 0;
while(left <= right){
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
ans+= maxright - height[right];
right--;
}
}
return ans;
}
};
```