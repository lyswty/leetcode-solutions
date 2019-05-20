class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>cnt;
        for(char x:s) cnt[x]++;
        for(char x:t) if(--cnt[x]<0) return x;
        return ' ';
    }
};
