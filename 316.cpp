class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        bool vis[26];
        memset(vis,0,sizeof(vis));
        for(char i:s) cnt[i-'a']++;
        string res="0";
        for(char i:s){
            cnt[i-'a']--;
            if(vis[i-'a']) continue;
            while(i<res.back()&&cnt[res.back()-'a']){
                vis[res.back()-'a']=false;
                res.pop_back();
            }
            res+=i;
            vis[i-'a']=true;
        }
        return res.substr(1);
    }
};
