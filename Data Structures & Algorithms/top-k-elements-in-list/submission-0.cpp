class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> buck(nums.size()+1);
        for(auto &it:mp){
            buck[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i=buck.size()-1;i>=0;i--){
            for(int num:buck[i]){
                ans.push_back(num);
                if(ans.size()==k){
                    return ans;

                }
            }
        }
        return ans;
    }
};
