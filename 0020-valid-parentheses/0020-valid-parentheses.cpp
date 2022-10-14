class Solution {
public:
    bool isValid(string st) {
        stack<char>s;
        for(auto i : st){
            if(i == '(' or i == '[' or i == '{')
                s.push(i);
            else
            {
                if(s.empty() or (s.top() == '(' and i != ')') or (s.top() == '[' and i != ']') or (s.top() == '{' and i != '}')) return false;
                s.pop();
            }
        }
        return s.empty();
    }
};