class Solution {
public:
    double myPow(double x, int n) {
        if(!n) return 1;
        if(fabs(x)<1e-8) return 0;
        if(fabs(x-1)<1e-8) return 1;
        if(fabs(x+1)<1e-8){
            if(n%2) return -1;
            else return 1;
        }
        if(n==-2147483648){
            n/=2;
            x*=x;
        }
        if(n<0){
            n=-n;
            x=1/x;
        }
        int neg=0;
        vector<int>v;
        while(n!=1){
            v.push_back(n%2);
            n/=2;
        }
        double out=x;
        for(int i=v.size()-1;i>=0;i--)
            if(v[i]) out*=x*out;
            else out*=out;
        return out;
    }
};
