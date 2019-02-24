class Solution {
public:
    string simplifyPath(string path) {
        deque<string>s;
        int i=0;
        string cur;
        while(i<path.size()+1){
            if(i==path.size()||path[i]=='/'&&cur.length()){
                if(cur==".."&&s.size()) s.pop_back();
                else if(cur!=".."&&cur!="."&&cur.length()) s.push_back(cur);
                cur.clear();
            }
            else if(path[i]!='/') cur+=path[i];
            i++;
        }
        if(s.empty()) return "/";
        else for(int i=0;i<s.size();i++) cur+='/'+s[i];
        return cur;
    }
};
