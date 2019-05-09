class Solution {
public:
    bool ispalindrome(string s){
        if(s.empty()) return true;
        for(int i=0;i<s.size()-1-i;i++) if(s[i]!=s[s.size()-1-i]) return false;
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>res;
        unordered_set<int>s;
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]=i;
            s.insert(words[i].size());
        }
        for(int i=0;i<words.size();i++){
            string w=words[i];
            reverse(w.begin(),w.end());
            if(mp.find(w)!=mp.end()&&mp[w]!=i){
                vector<int>cur;
                cur.push_back(i);
                cur.push_back(mp[w]);
                res.push_back(cur);
            }
            for(int j=words[i].size()-1;j>=0;j--){
                if(s.find(j)==s.end()) continue;
                string w1=words[i].substr(0,j),w2=words[i].substr(words[i].size()-j);
                if(ispalindrome(words[i].substr(j))){
                    reverse(w1.begin(),w1.end());
                    if(mp.find(w1)!=mp.end()){
                        vector<int>cur;
                        cur.push_back(i);
                        cur.push_back(mp[w1]);
                        res.push_back(cur);
                    }
                }
                if(ispalindrome(words[i].substr(0,words[i].size()-j))){
                    reverse(w2.begin(),w2.end());
                    if(mp.find(w2)!=mp.end()){
                        vector<int>cur;
                        cur.push_back(mp[w2]);
                        cur.push_back(i);
                        res.push_back(cur);
                    }
                }
            }
        }
        return res;
    }
};
