class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        string res;
        long n=numerator,m=denominator;
        if(n<0&&m>0||n>0&&m<0) res+='-';
        if(n<0) n=-n;
        if(m<0) m=-m;
        unordered_map<int,int>mod;
        res+=to_string(n/m);
        if(n%m==0) return res;
        else res+='.';
        n%=m;
        while(n){
            if(mod.find(n)!=mod.end()){
                res.insert(res.end(),')');
                res.insert(res.begin()+mod[n],'(');
                break;
            }
            mod[n]=res.size();
            n*=10;
            res+=to_string(n/m);
            n%=m;
        }
        return res;
    }
};
