class Solution {
public:
    int getSum(int a, int b) {
        if(!b) return a;
        int sum=a^b,carry=a&b;
        if(carry<0) carry=(carry&INT_MAX)<<1;
        else carry<<=1;
        return getSum(sum,carry);
    }
};
