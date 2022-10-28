class NumArray {
private:
    vector<int>accsum;
public:
    NumArray(vector<int>& nums) {
        accsum.push_back(0);
        for(int num : nums){
            accsum.push_back(accsum.back()+num);
        }
    }
    
    int sumRange(int left, int right) {
        return accsum[right+1] - accsum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */