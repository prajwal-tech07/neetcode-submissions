class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int fix=-nums[i];
            int st=i+1;
            int end=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            while(st<end){ 
            if(nums[st]+nums[end]==fix){
                    result.push_back({nums[i],nums[st],nums[end]});
                    st++;
                    end--;
            while(st<end && nums[st]==nums[st-1]){
                st++;
            }
            while(st<end && nums[end]==nums[end+1]){
                end--;
            }
            }
            else if(nums[st]+nums[end]<fix){
                st++;
            }else{
                end--;
            }
           
            
            }
        }
        return result;
    }
};
