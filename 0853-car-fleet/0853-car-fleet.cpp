class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;
        
        for(int i=0; i<position.size(); i++){
            double time = (double)(target-position[i])/speed[i];
            cars.push_back({position[i], time});
        }
        
        sort(cars.begin(), cars.end());
        
        double maxtime = 0.0;
        int result = 0;
        
        for(int i=position.size()-1; i>=0; i--){
            double time = cars[i].second;
            if(time > maxtime){
                maxtime = time;
                result++;
            }
        }
        return result;
    }
};