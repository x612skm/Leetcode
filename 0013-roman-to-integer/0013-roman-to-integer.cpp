class Solution {
public:
    int romanToInt(string s) {
        //we have to maintation a dictionary to the romans to numberic
        //HAving a value and its key
        unordered_map<char, int> table = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D', 500}, {'M',1000}};

        int nums = 0;
        for(int i=0; i<s.size()-1; ++i){
            if(table[s[i]] < table[s[i+1]])
                nums -= table[s[i]];
            else
                nums += table[s[i]];
        }
        nums = nums + table[s.back()];// having the last element
        return nums;
    }
};