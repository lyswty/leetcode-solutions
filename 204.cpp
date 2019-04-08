class Solution {
public:
    int countPrimes(int n) {
        if(n<3) return 0;
        int cnt=0;
        vector<bool>deleted(n,false);
        int cur=2;
        while(cur<n){
            for(int i=cur;i<n;i+=cur) deleted[i]=true;
            if(cur==2) cur--;
            for(cur+=2;deleted[cur];cur+=2);
            cnt++;
        }
        return cnt;
    }
};
