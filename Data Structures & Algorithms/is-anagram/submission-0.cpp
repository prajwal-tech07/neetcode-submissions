class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vec1(26,0);
        vector<int> vec2(26,0);
        for(int i=0;i<s.length();i++){
           vec1[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
           vec2[t[i]-'a']++;
        }
        if(vec1==vec2){
            return true;
        }
        return false;
    }
};
