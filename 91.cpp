class Solution {
public:
    int numDecodings(string s) {
        if(!s.size()||s[0]=='0') return 0;
        if(s.size()==1) return 1;
        int *dp=new int[s.size()];
        dp[0]=1;
        if(stoi(s.substr(0,2))<=26&&s[1]!='0') dp[1]=2;
        else if(s[1]!='0'||stoi(s.substr(0,2))<=26) dp[1]=1;
        else return 0;
        for(int i=2;i<s.size();i++){
            if(dp[i-1]==0&&dp[i-2]==0) return 0;
            int a1,a2;
            if(s[i]=='0') a1=0;
            else a1=dp[i-1];
            if(s[i-1]=='0') a2=0;
            else if(s[i]=='0'){
                if(stoi(s.substr(i-1,2))<=26) a2=dp[i-2];
                else a2=0;
            }
            else if(stoi(s.substr(i-1,2))<=26) a2=dp[i-2];
            else a2=0;
            dp[i]=a1+a2;
        }
        return dp[s.size()-1];
    }
};
