class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i=s.size()/2;i>0;i--){
            if(s.size()%i) continue;
            bool judge=true;
            for(int j=i;j<s.size();j+=i) if(s.substr(0,i)!=s.substr(j,i)){
                judge=false;
                break;
            } 
            if(judge) return true;
        }
        return false;
    }
};
