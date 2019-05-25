class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>cnt;
        for(char x:s) cnt[x]++;
        int res=s.size();
        bool flag=false;
        for(auto it=cnt.begin();it!=cnt.end();it++) if(it->second%2){
            if(flag) res--;
            else flag=true;
        }
        return res;
    }
};
