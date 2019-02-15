class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>>dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0]=true;
        for(int j=1;j<=p.size();j++) if(p[j-1]=='*') dp[0][j]=dp[0][j-1];
        for(int i=1;i<=s.size();i++) for(int j=1;j<=p.size();j++){
            if(p[j-1]!='*'){
                if(p[j-1]=='?'||p[j-1]==s[i-1]) dp[i][j]=dp[i-1][j-1];
            }
            else dp[i][j]=dp[i-1][j]||dp[i][j-1]||dp[i-1][j-1];
        }
        return dp[s.size()][p.size()];
    }
};

//一开始用了用递归回溯，超时

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        if(!s.size()){
            for(int i=0;i<p.size();i++) if(p[i]!='*') return false;
            return true;
        }
        if(!p.size()) return false;
        if(p[0]=='?'||s[0]==p[0]) return isMatch(s.substr(1),p.substr(1));
        if(p[0]!='*') return false;
        int j=1;
        for(;j<p.size()&&p[j]=='*';j++);
        if(j==p.size()) return true;
        for(int i=0;i<s.size();i++) if(isMatch(s.substr(i),p.substr(j))) return true;
        return false;
    }
};
*/
