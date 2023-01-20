class Solution {
private:
    int sum(int n){
        int s = 0;
        while(n){
            int t = n%10;
            s += t*t;
            n/=10;
        }
        return s;
    }
public:
    //using floyd cycle detection algorithm
    bool isHappy(int n) {
        int l1 = n; int l2 = sum(n);
        while(l1 != l2){
            l1 = sum(l1);
            l2 = sum(sum(l2));
        }
        return l1 == 1;
    }
};