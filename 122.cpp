class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=-1,profit=0;
        for(int i=0;i<prices.size();i++){
            if(min<0||prices[i]<min) min=prices[i];
            if(prices[i]>min){
                profit+=prices[i]-min;
                min=prices[i];
            }
        }
        return profit;
    }
};
