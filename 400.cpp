class Solution {
public:
    int findNthDigit(int n) {
        if(n<10) return n;
        long c[10];
        c[1]=9;
        int t=0;
        for(int i=2;i<10;i++){
            c[i]=c[i-1]+9*i*pow(10,i-1);
            if(n>=c[i-1]&&c[i]>=n) t=i;
        }
        n-=c[t-1];
        string x=to_string(pow(10,t-1)-1+(int)(n+1)/t);
        return x[(n-1)%t]-'0';
    }
};
