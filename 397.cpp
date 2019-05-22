class Solution {
public:
    int integerReplacement(int n) {
        if(n==1) return 0;
        else if(n%2) return min(integerReplacement(n/2+1)+1,integerReplacement(n-1))+1;
        else return integerReplacement(n/2)+1;
    }
};
