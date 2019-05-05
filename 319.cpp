class Solution {
public:
    int bulbSwitch(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++) if((int)sqrt(i)*sqrt(i)==i) cnt++;
        return cnt;
    }
};
