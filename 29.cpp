class Solution {
public:
    int divide(int dividend, int divisor) {
      //方法实在太傻了- -
        if((dividend==-2147483648&&divisor==-1)||!divisor) return 2147483647;
        if(dividend==-2147483648&&divisor==-2147483648) return 1;
        if(dividend==-2147483648&&divisor==1) return -2147483648;
        if(divisor==-2147483648) return 0;
        if(!dividend) return 0;
        int cnt=0;
        bool neg=0;
        if(dividend==-2147483648){
            if(divisor>0) dividend+=divisor;
            else dividend-=divisor;
            cnt++;
        }
        if(dividend>0&&divisor<0){
            neg=1;
            divisor=-divisor;
        }
        else if(dividend<0&&divisor>0){
            neg=1;
            dividend=-dividend;
        }
        else if(dividend<0&&divisor<0){
            dividend=-dividend;
            divisor=-divisor;
        }
        while(dividend>=divisor){
            dividend-=divisor;
            cnt++;
        }
        if(neg) return -cnt;
        else return cnt;
    }
};
