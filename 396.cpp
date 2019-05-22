class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.empty()) return 0;
        long sum=0,res,last=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            last+=A[i]*i;
        }
        res=last;
        for(int i=1;i<A.size();i++){
            last+=sum-A[A.size()-i]-(A.size()-1)*A[A.size()-i];
            res=max(last,res);
        }
        return res;
    }
};
