class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // LOGIC IS clear wherever there is 0 => -1 then count the longest sum 0
        unordered_map<int, int>mp;
        mp[0] = -1;
        
        int sum = 0; int longest_sub = 0;
        
        for(int i=0; i<(int)nums.size(); i++){
            //add -1 to the sum
            sum += nums[i] == 0 ? -1 : 1;
            
            auto it = mp.find(sum);
            if(it != mp.end()){
                if(longest_sub < i - mp[sum])
                {longest_sub = i - mp[sum]; cout<<longest_sub<<" ";}
            }
            else{
                mp[sum] = i;
            }
        }
        return longest_sub;
    }
};