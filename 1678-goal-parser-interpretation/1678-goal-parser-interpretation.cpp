class Solution {
public:
    string interpret(string command) {
        string s = "";
        
        for(int i=0; i<command.length(); i++){
            if(command[i] == 'G')
                s+= "G";
            
            else if(command[i] == '(')
            {
                if(command[++i] == ')')
                    s+="o";
                else 
                    s+="al";
            }
        }
        return s;
    }
};