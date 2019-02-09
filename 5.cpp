class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1000][1000];
        memset(dp,0,sizeof(dp));
        int max=0;
        string out;
        out+=s[0];
        for(int i=0;i<s.size();i++){
            dp[i][i]=1;
            if(i>0&&s[i]==s[i-1]){
                dp[i-1][i]=1;
                if(!max){
                    max=1;
                    out=s.substr(i-1,2);
                }
            }
        }
        for(int r=2;r<s.size();r++) for(int l=0;l<r-1;l++){
            if(dp[l+1][r-1]&&s[l]==s[r]){
                dp[l][r]=1;
                if(max<r-l){
                    max=r-l;
                    out=s.substr(l,r-l+1);
                }
            }
        }
        return out;
    }
};
