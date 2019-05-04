class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>index(primes.size(),0),res(1,1);
        while(res.size()<n){
            int MIN=INT_MAX,minidx=-1;
            for(int j=0;j<primes.size();j++) if(res[index[j]]*primes[j]<MIN){
                MIN=res[index[j]]*primes[j];
                minidx=j;
            }
            if(MIN!=res[res.size()-1]) res.push_back(MIN);
            index[minidx]++;
        }
        return res[res.size()-1];
    }
};
