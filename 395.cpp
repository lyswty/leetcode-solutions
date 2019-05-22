class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.empty()||s.size()<k) return 0;
        unordered_map<char,int>cnt;
        for(char c:s) cnt[c]++;
        int i=0;
        while(i<s.size()&&cnt[s[i]]>=k) i++;
        if(i==s.size()) return s.size();
        int l=longestSubstring(s.substr(0,i),k);
        while(i<s.size()&&cnt[s[i]]<k) i++;
        int r=longestSubstring(s.substr(i),k);
        return max(l,r);
    }
};
