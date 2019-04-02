class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        vector<string>res;
        for(int i=0;i+9<s.size();i++){
            string cur=s.substr(i,10);
            if(mp[cur]++==1) res.push_back(cur);
        }
        return res;
    }
};
