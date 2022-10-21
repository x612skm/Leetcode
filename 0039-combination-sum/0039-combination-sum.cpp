class Solution {
private:
    void combinationSum(vector<int>&candidates, int target, vector<vector<int>>&result, vector<int>&temp_storage, int index){
        if(target == 0)
        {
            result.push_back(temp_storage);
            return;
        }
        //there we check for the negative nuber and for the index not going out of bound
        while(index < size(candidates) and target - candidates[index] >= 0){
            temp_storage.push_back(candidates[index]);
            //recurance for the next
            combinationSum(candidates, target-candidates[index], result, temp_storage, index);
            //increasing the index to check the next;
            ++index;
            cout<<index<<" ";
            //back track aagain keeping the numbver out
            temp_storage.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //simple backtracking problem
        sort(candidates.begin(), candidates.end());
        //remove the duplicate if asked in the array else not given in thisquestion
        //candidates.erase(unique(candidates.begin(), candidates.end(), candidates.end()));
        
        vector<vector<int>> result;
        vector<int>temp_storage;
        
        combinationSum(candidates, target, result, temp_storage, 0);
        return result;
    }
};