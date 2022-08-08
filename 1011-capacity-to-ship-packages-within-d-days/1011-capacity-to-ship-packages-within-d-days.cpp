class Solution {
public:
    int helper(vector<int>weights, int mid, int days){
        int count = 1;
        int sum = 0;
        //add all the weights
        
        for(int i=0; i<weights.size();i++){
            sum=sum+weights[i];
            if(weights[i]> mid) return false;
            if(sum > mid){
                count++;
                sum = weights[i];
                
            }
        }
        if(count <= days)
            return true;
        return false;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int result = INT_MAX;
        int maxCapacity;
        
        for(int i=0; i<n; i++)
            maxCapacity += weights[i];
        
        int low = *max_element(weights.begin(), weights.end());
        int high = maxCapacity;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            //here comes the helper function
            if(helper(weights,mid,days)){ 
                //when it is true check for the next right to left to reduce the space
                result = min(result,mid);//add the mid to the result it is the answer
                high = mid-1;
            }
            else
                low = mid +1;
        }
        return result;
    }
};