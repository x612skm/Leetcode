class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        
        if(num1==0 && num2==0)
            return 0;
        
        if(num1 == num2)
            return count = 1;
        
        while(num1 != 0 && num2!=0){
            if(num1 >= num2){
                num1 = num1 - num2;
                count++;
            }
            else if(num2 >= num1){
                num2 = num2-num1;
                count++;
            }
        }
        return count;
    }
};