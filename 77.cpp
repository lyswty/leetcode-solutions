class Solution {
public:
    void DFS(vector<vector<int>>&out,vector<int>&cur,int n,int k,int i){
        cur.push_back(i);
        if(cur.size()==k){
            out.push_back(cur);
            return;
        }
        for(int j=i+1;j<=n;j++){
            DFS(out,cur,n,k,j);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>out;
        vector<int>cur;
        if(!k||!n) return out;
        for(int i=1;i<=n-k+1;i++){
            DFS(out,cur,n,k,i);
            cur.pop_back();
        }
        return out;
    }
};
