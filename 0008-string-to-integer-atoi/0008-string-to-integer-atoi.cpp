class Solution {
private:
    bool isDigit(char ch){
        return ch>='0' and ch<='9';
    }
public:
    int myAtoi(string s) {
        int len = s.size();
        if(len == 0)
            return 0;
        
        int index = 0;
        
        while(index<len and s[index]==' ')
            index++;
        
        if(index == len)
            return 0;
        
        char ch;
        bool isNegative = (ch = s[index]) == '-';
        
        if(isNegative or ch == '+')
            ++index;
        
        const int maxlimit = INT_MAX/10;
        
        int result = 0;
        
        while(index < len and isDigit(ch = s[index])){
            int digit = ch -'0';
            
            if(result > maxlimit or (result == maxlimit and digit > 7)){
                return isNegative ? INT_MIN : INT_MAX;
            }
            result = (result * 10) + digit;
            ++index;
        }
        return isNegative ? -result : result; 
    }
};