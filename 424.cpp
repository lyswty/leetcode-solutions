class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxcnt=0,l=0,r;
        vector<int>cnt(128,0);
        for(r=0;r<s.size();r++){
            maxcnt=max(maxcnt,++cnt[s[r]]);
            if(r-l+1-maxcnt>k) cnt[s[l++]]--;
        }
        return r-l;
    }
};
