class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int left=0,lc=n,rc=n;
        string a;
        vector<string>v;
        dfs(v,a,lc,rc,left);
        return v;
    }
    void dfs(vector<string>&v,string& now,int lc,int rc,int left){
        if(lc){
            lc--;
            left++;
            now+='(';
            dfs(v,now,lc,rc,left);
            lc++;
            left--;
            now.pop_back();
        }
        if(rc&&left){
            rc--;
            left--;
            now+=')';
            dfs(v,now,lc,rc,left);
            rc++;
            left++;
            now.pop_back();
        }
        if(!lc&&!rc) v.push_back(now);
    }
};
