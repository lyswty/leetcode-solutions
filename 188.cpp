class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k<1) return 0;
        if(k<prices.size()/2){
            pair<int,int>*p=new pair<int,int>[k];
            for(int i=0;i<k;i++) p[i].first=INT_MIN,p[i].second=0;
            for(int i:prices){
                p[0].first=max(p[0].first,-i);
                p[0].second=max(p[0].second,p[0].first+i);
                for(int j=1;j<k;j++){
                    p[j].first=max(p[j].first,p[j-1].second-i);
                    p[j].second=max(p[j].second,p[j].first+i);
                }
            }
            return p[k-1].second;
        }
        else{
            int res=0;
            for(int i=1;i<prices.size();i++) if(prices[i]>prices[i-1]) res+=prices[i]-prices[i-1];
            return res;
        }
    }
};
