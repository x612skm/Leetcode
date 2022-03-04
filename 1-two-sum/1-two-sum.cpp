#include <unordered_map>
#include <iostream> 
#include <vector>

using std::unordered_map;
using std::vector;

/*
target = 9
check a number minus by target
agar wo mere list my hay to well and good
kya negative karne se zero aya 
nahi => remaining ke lie next se minus karo
agar tb bhi nhi aya to 
next wla first point ho jayga

*/
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
       int n = nums.size();
        vector<int>ans;
        
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++){
            if(mp.find(target-nums[i]) != mp.end()){ //agar humko target milega to push karenge 
                
                ans.push_back(mp[target-nums[i]]);//target ka value
                
                ans.push_back(i);//target ka index
                return ans;
                
            }
            else
                mp[nums[i]] = i;
        }
        return ans;//kuch nahi mila to ans return
        
    }
  
};