class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=-1,max=0;
        for(int i=0;i<prices.size();i++){
            if(min<0||prices[i]<min) min=prices[i];
            if(prices[i]>min&&prices[i]-min>max) max=prices[i]-min;
        }
        return max;
    }
};
