class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<pair<unordered_map<long,int>,unordered_map<long,int>>>dp(A.size());
        int res=0;
        for(int i=1;i<A.size();i++) for(int j=0;j<i;j++){
            long distance=(long)A[i]-A[j];
            dp[i].second[distance]++;
            if(dp[j].second.find(distance)!=dp[j].second.end()){
                dp[i].first[distance]+=dp[j].second[distance];
                res+=dp[j].second[distance];
            }
            if(dp[j].first.find(distance)!=dp[j].first.end()){
                dp[i].first[distance]+=dp[j].first[distance];
                res+=dp[j].first[distance];
            }
        }
        return res;
    }
};
