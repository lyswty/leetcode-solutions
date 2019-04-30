class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        vector<int>buy(prices.size(),0),sell(prices.size(),0),cool(prices.size(),0);
        buy[0]=-prices[0];
        for(int i=1;i<prices.size();i++){
            sell[i]=buy[i-1]+prices[i];
            buy[i]=max(cool[i-1]-prices[i],buy[i-1]);
            cool[i]=max(cool[i-1],sell[i-1]);
        }
        return max(sell[prices.size()-1],cool[prices.size()-1]);
    }
};
