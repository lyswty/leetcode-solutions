class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,max=0;
        for(int i=0;i<prices.size();i++) for(int j=i+1;j<prices.size();j++) if(prices[j]>prices[i]){
            profit=prices[j]-prices[i];
            int min=-1,MAX=0;
            for(int a=j+1;a<prices.size();a++){
                if(min<0||prices[a]<min) min=prices[a];
                if(prices[a]>min&&prices[a]-min>MAX) MAX=prices[a]-min;
            }
            profit+=MAX;
            if(profit>max) max=profit;
        }
        return max;
    }
};
