class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int maxlen=0;
        unordered_set<char> win;
        for(int right=0;right<s.length();right++){
            while(win.find(s[right])!=win.end()){
                win.erase(s[left]);
                left++;
            }
            win.insert(s[right]);
            maxlen=max(maxlen,right-left+1);
        }
    return maxlen;
}
};
