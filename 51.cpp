/*本来想着用vector先把之前的位置都保存起来，然后判断是否合理的时候就只需要遍历这个vector就可以了，发现比别人遍历三次的还慢很多
然后就想着是不是因为vector的push和back速度比较慢，改成了list，然后更慢- -*/
class Solution {
public:
    vector<vector<string>>out;
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
                    out.push_back(v);
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
    vector<vector<string>> solveNQueens(int n) {
        vector<string>cur(n,string(n,'.'));
        DFS(0,cur);
        return out;
    }
};
