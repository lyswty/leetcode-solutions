//滑动窗口法，思路差不多，但是我写的就太- -了
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>tmp;
        unordered_set<char>ts;
        for(int i=0;i<t.size();i++){
            tmp[t[i]]++;
            ts.insert(t[i]);
        }
        int end=0,min=INT_MAX;
        string out;
        unordered_map<char,int>smp;
        unordered_set<char>ss;
        vector<int>pos;
        int curpos=0;
        while(end<s.size()){
            if(ts.find(s[end])!=ts.end()){
                pos.push_back(end);
                smp[s[end]]++;
                if(smp[s[end]]==tmp[s[end]]) ss.insert(s[end]);
                if(smp[s[end]]>tmp[s[end]]&&s[end]==s[pos[curpos]]){
                    smp[s[end]]--;
                    ++curpos;
                }
                while(ss.size()==ts.size()){
                    if(end-pos[curpos]<min){
                        min=end-pos[curpos];
                        out=s.substr(pos[curpos],end-pos[curpos]+1);
                    }
                    curpos++;
                    if(--smp[s[pos[curpos-1]]]<tmp[s[pos[curpos-1]]]) ss.erase(s[pos[curpos-1]]);
                }
            }
            end++;
        }
        return out;
    }
};
