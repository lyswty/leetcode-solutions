class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        int i=0;
        unordered_map<char,string>mp;
        unordered_map<string,char>mpsc;
        string cur;
        while(ss>>cur){
            if(i==pattern.size()) return false;
            if(mp[pattern[i]].size()&&mp[pattern[i]]!=cur||mpsc.find(cur)!=mpsc.end()&&mpsc[cur]!=pattern[i]) return false;
            mp[pattern[i]]=cur;
            mpsc[cur]=pattern[i];
            i++;
        }
        if(i!=pattern.size()) return false;
        return true;
    }
};
