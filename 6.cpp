class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int x=2+2*(numRows-2);
        string out;
        for(int i=0;i<s.size();i+=x) out+=s[i];
        for(int r=1;r<numRows-1;r++){
            out+=s[r];
            for(int i=r+x;i-2*r<s.size();i+=x){
                out+=s[i-2*r];
                if(i<s.size()) out+=s[i];
            }
        }
        for(int i=numRows-1;i<s.size();i+=x) out+=s[i];
        return out;
    }
};
