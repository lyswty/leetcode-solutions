class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>out;
        for(int i=0;i<strs.size();i++){
            string cur=strs[i];
            sort(cur.begin(),cur.end());
            mp[cur].push_back(strs[i]);
        }
        for(auto it=mp.begin();it!=mp.end();it++) out.push_back(it->second);
        return out;
    }
};
