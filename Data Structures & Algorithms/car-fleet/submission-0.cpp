class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars(speed.size());
        for(int i=0;i<speed.size();i++){
            double arrTime=(double)(target-position[i])/(double)speed[i];
            cars[i]={position[i],arrTime};
        }
        int fleet=1;
        sort(cars.begin(),cars.end());
        double earlyTime=cars.back().second;
        for(int i=cars.size()-2;i>=0;i--){
            if(cars[i].second>earlyTime){
               fleet++;
               earlyTime=cars[i].second;
            }
        }
        return fleet;
    }
};
