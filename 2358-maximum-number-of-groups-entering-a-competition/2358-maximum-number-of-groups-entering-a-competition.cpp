class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        //mathematical approach
        return (int)((sqrt(1+8*grades.size())-1)/2);
    }
};

