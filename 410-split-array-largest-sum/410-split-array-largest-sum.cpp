class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int start = 0;
        int end = 0;

        for(int i=0; i<nums.size(); i++){
        	start = max(start, nums[i]);
        	end += nums[i];
        }

        //binary search
        while(start < end){
        	int mid = start + (end - start)/2;

        	int sum =0;
        	int pieces = 1;

        	for(auto num : nums){
        		if(sum + num > mid){
        			/*// you cannot add this in this subarray, make new one
                    // say you add this num in new subarray, then sum = num*/
                   sum = num;
                   pieces++; 
        		}else{
        			sum += num;
        		}
        	}

        	if(pieces > m){
        		start = mid+1;
        	}
        	else{
        		end = mid;
        	}
        }
        return end; // start = end;
    }
};