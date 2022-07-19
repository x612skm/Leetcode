class Solution {
public:
    bool isPowerOfFour(int n) {
        //base case for the following
        if(n<1) return false;
        if(n==1) return true;
        //recursive code
        return n%4==0 && isPowerOfFour(n/4);
    }
};