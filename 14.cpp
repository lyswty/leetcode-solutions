class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int minl=INT_MAX;
        for(int i=0;i<strs.size();i++) if(strs[i].length()<minl) minl=strs[i].length();
        string out;
        for(int i=0;i<minl;i++){
            for(int j=1;j<strs.size();j++) if(strs[j][i]!=strs[0][i]) return out;
            out+=strs[0][i];
        }
        return out;
    }
};
