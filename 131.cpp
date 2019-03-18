class Solution {
public:
    vector<vector<string>>output;
    void DFS(vector<vector<string>>&out,vector<vector<bool>>&dp,int x,const string &s){
        if(x==s.size()) output.insert(output.end(),out.begin(),out.end());
        vector<vector<string>>cur=out;
        for(int i=x;i<s.size();i++){
            if(dp[x][i]){
                if(out.empty()) out.push_back(vector<string>(1,s.substr(x,i-x+1)));
                else for(int j=0;j<out.size();j++) out[j].push_back(s.substr(x,i-x+1));
                DFS(out,dp,i+1,s);
                out=cur;
            }
            else continue;
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        for(int i=0;i<s.size();i++){
            dp[i][i]=true;
            if(i&&s[i]==s[i-1]) dp[i-1][i]=true;
            else if(i&&s[i]!=s[i-1]) dp[i-1][i]=false;
        }
        for(int i=2;i<s.size();i++) for(int j=0;j+i<s.size();j++)
            if(s[j]==s[i+j]&&dp[j+1][i+j-1]) dp[j][j+i]=true;
            else dp[j][j+i]=false;
        vector<vector<string>>out;
        DFS(out,dp,0,s);
        return output;
    }
};
