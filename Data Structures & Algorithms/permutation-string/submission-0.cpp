class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<s1.length();i++){
            mp1[s1[i]]++;
        }
        int left=0;
        
        for(int right=0;right<s2.length();right++){
            mp2[s2[right]]++;
             while(right-left+1 > s1.length()){
                mp2[s2[left]]--;
                if(mp2[s2[left]]==0){
                    mp2.erase(s2[left]);
                }
                left++;
            }
            if(mp1==mp2){
                return true;
            }
           
        }
        return false;
    }
};
