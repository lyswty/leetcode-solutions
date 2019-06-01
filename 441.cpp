class Solution {
public:
    int arrangeCoins(int n) {
        int sum=0,i;
        for(i=1;n-sum>=i;i++) sum+=i;
        return i-1;
    }
};
