class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     unordered_set<int> s;
     for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);
     }   
    
    int longest=0;
    for(int i=0;i<nums.size();i++){
        if(s.count(nums[i]-1)==0){
            int length=1;
            int current=nums[i];

            while(s.count(current+1)!=0){
                length++;
                current++;
            }
            longest=max(longest,length);
        }
    }
    return longest;
    }
};
