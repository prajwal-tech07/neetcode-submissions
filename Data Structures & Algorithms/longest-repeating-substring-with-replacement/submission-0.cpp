class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int maxlen=0;
        int maxfreq=0;
        unordered_map<char,int> mp1;
        for(int right=0;right<s.size();right++){
            mp1[s[right]]++;
            maxfreq=max(maxfreq,mp1[s[right]]);
            while(right-left+1 - maxfreq > k){
                mp1[s[left]]--;
                left++;
            }
            
            maxlen=max(maxlen,right-left+1);

        }
        return maxlen;
    }
};
