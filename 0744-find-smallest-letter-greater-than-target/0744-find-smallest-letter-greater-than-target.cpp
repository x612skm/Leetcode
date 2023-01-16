class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0; int end = letters.size()-1;
        if(target < letters[0] or target >= letters[letters.size()-1])
            return letters[0];
        while(start <= end){
            int mid = start + (end - start)/2;
            //checking for the out-of bound conditons
            if(letters[mid] <= target)
                start = mid + 1;
            if(letters[mid] > target)
                end = mid-1;
        }
        return letters[start];
    }
};