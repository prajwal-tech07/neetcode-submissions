class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        
        for(int i=0;i<temperatures.size();i++){
            bool flag=false;
            for(int j=i+1;j<temperatures.size();j++){
                if(temperatures[i]<temperatures[j]){
                    result.push_back(j-i);
                    flag=true;
                    break;
                }

            }
            if(!flag){
                result.push_back(0);
            }

        }
        
        return result;
    }
};
