class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=1;
        if(n==1) return 1;
        for(int i=2;i<n;i++){
            swap(a,b);
            b=a+b;
        }
        return a+b;
    }
};
