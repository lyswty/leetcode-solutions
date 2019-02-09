class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int out=1,last=0;
        unordered_map<char,int>mp;
        for(int i=1;i<=s.size();i++){
            if(mp[s[i-1]]>last) last=mp[s[i-1]];
            int cur=i-last;
            out=max(out,cur);
            mp[s[i-1]]=i;
        }
        return out;
    }
};
