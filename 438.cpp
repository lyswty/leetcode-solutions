class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        if(s.size()<p.size()) return res;
        map<char,int>pcnt,scnt;
        for(char x:p) pcnt[x]++;
        for(int i=0;i<p.size();i++) scnt[s[i]]++;
        if(scnt==pcnt) res.push_back(0);
        for(int i=0;i+p.size()<s.size();i++){
            if(!--scnt[s[i]]) scnt.erase(s[i]);
            scnt[s[i+p.size()]]++;
            if(scnt==pcnt) res.push_back(i+1);
        }
        return res;
    }
};
