class Solution {
public:
    int trailingZeroes(int n) {
        int sum=0;
        for(int i=n/5;i;i/=5) sum+=i;
        return sum;
    }
};
