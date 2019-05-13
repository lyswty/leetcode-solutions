class Solution {
public:
    static bool cmp(const vector<int>&a,const vector<int>&b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) return 0;
        int res=1;
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>dp(envelopes.size(),1);
        for(int i=1;i<envelopes.size();i++){
            for(int j=0;j<i;j++) if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1]) dp[i]=max(dp[i],dp[j]+1);
            if(res<dp[i]) res=dp[i];
        }
        return res;
    }
};
