class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>cnt;
        for(char x:s) cnt[x]++;
        for(int i=0;i<s.size();i++) if(cnt[s[i]]==1) return i;
        return -1;
    }
};
