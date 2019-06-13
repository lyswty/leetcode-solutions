class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        int cnt=0;
        for(int i=S.size()-1;i>=0;i--){
            if(S[i]=='-') continue;
            res+=toupper(S[i]);
            if(++cnt==K){
                res+='-';
                cnt=0;
            }
        }
        if(res.back()=='-') res.pop_back();
        return string(res.rbegin(),res.rend());
    }
};
