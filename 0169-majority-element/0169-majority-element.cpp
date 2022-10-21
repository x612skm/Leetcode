class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //intorducing the boyer moore voting algorithm for majority
        int counter = 1; int majority_element = nums[0];
        //int majority_element;
        for(int i=1; i<nums.size(); i++){
            if(counter == 0){
                majority_element = nums[i]; 
                counter++;
            }
            else if(majority_element == nums[i]){
                counter++;
            }
            else
            {
                counter--;
            }
        }
        return majority_element;
    }
};