class Solution {
public:
    bool isvalid(string s){
        int cnt=0;
        for(char x:s){
            if(x=='(') cnt++;
            else if(x==')') cnt--;
            if(cnt<0) return false;
        }
        return !cnt;
    }
    vector<string> removeInvalidParentheses(string s) {
        queue<string>q;
        unordered_set<string>S;
        vector<string>res;
        q.push(s);
        int length=-1;
        while(q.size()&&(int)q.front().size()>=length){
            string cur=q.front();
            q.pop();
            if(isvalid(cur)){
                res.push_back(cur);
                length=cur.size();
            }
            if(length==-1) for(int i=0;i<cur.size();i++) if(cur[i]=='('||cur[i]==')'){
                string next=cur.substr(0,i)+cur.substr(i+1);
                if(S.find(next)==S.end()){
                    S.insert(next);
                    q.push(next);
                }
            }
        }
        return res;
    }
};
