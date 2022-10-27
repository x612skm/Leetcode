class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int counterone = 0;
        int counterflip = 0;
        
        for(auto& ch : s){
            if(ch == '1')
            {counterone++; }
            
            else
            {counterflip++; }
            
            counterflip = min(counterone, counterflip);
            
        }
        return counterflip;
    }
};