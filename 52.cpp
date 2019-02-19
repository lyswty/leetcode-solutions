class Solution {
public:
    int out=0;
    list<pair<int,int>>queen;
    bool judge(int x,int y,vector<string> v){
        if(!x) return true;
        for(auto it=queen.begin();it!=queen.end();it++) if((*it).second==y||(*it).first+(*it).second==x+y||(*it).first-(*it).second==x-y) return false;
        return true;
    }
    void DFS(int x,vector<string>& v){
        for(int i=0;i<v.size();i++){
            if(judge(x,i,v)){
                v[x][i]='Q';
                if(x+1==v.size()){
                    out++;
                    v[x][i]='.';
                    return;
                }
                queen.push_back(pair<int,int>(x,i));
                DFS(x+1,v);
                v[x][i]='.';
                queen.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>cur(n,string(n,'.'));
        DFS(0,cur);
        return out;
    }
};
