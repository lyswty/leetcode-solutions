class Solution {
public:
    void DFS(vector<vector<bool>>& vis,vector<vector<int>>& matrix,vector<vector<pair<int,int>>>& m,int i,int j){
        vis[i][j]=true;
        if(i==0||j==0) m[i][j].first=true;
        if(i==matrix.size()-1||j==matrix[0].size()-1) m[i][j].second=true;
        if(m[i][j].first==1&&m[i][j].second==1) return;
        vector<pair<int,int>>equal;
        if(i&&matrix[i][j]>=matrix[i-1][j]){
            if(matrix[i][j]==matrix[i-1][j]) equal.push_back(make_pair(i-1,j));
            if(!vis[i-1][j]&&m[i-1][j].first==-1){
                DFS(vis,matrix,m,i-1,j);
                vis[i-1][j]=false;
            }
            if(m[i-1][j].first==1) m[i][j].first=1;
            if(m[i-1][j].second==1) m[i][j].second=1;
        }
        if(i!=matrix.size()-1&&matrix[i][j]>=matrix[i+1][j]){
            if(matrix[i][j]==matrix[i+1][j]) equal.push_back(make_pair(i+1,j));
            if(!vis[i+1][j]&&m[i+1][j].first==-1){
                DFS(vis,matrix,m,i+1,j);
                vis[i+1][j]=false;
            }
            if(m[i+1][j].first==1) m[i][j].first=1;
            if(m[i+1][j].second==1) m[i][j].second=1;
        }
        if(j&&matrix[i][j]>=matrix[i][j-1]){
            if(matrix[i][j]==matrix[i][j-1]) equal.push_back(make_pair(i,j-1));
            if(!vis[i][j-1]&&m[i][j-1].first==-1){
                DFS(vis,matrix,m,i,j-1);
                vis[i][j-1]=false;
            }
            if(m[i][j-1].first==1) m[i][j].first=1;
            if(m[i][j-1].second==1) m[i][j].second=1;
        }
        if(j!=matrix[0].size()-1&&matrix[i][j]>=matrix[i][j+1]){
            if(matrix[i][j]==matrix[i][j+1]) equal.push_back(make_pair(i,j+1));
            if(!vis[i][j+1]&&m[i][j+1].first==-1){
                DFS(vis,matrix,m,i,j+1);
                vis[i][j+1]=false;
            }
            if(m[i][j+1].first==1) m[i][j].first=1;
            if(m[i][j+1].second==1) m[i][j].second=1;
        }
        if(m[i][j].first==1||m[i][j].second==1) for(auto x:equal){
            if(m[i][j].first==1) m[x.first][x.second].first=1;
            if(m[i][j].second==1) m[x.first][x.second].second=1;
        }
        if(m[i][j].first==-1) m[i][j].first=0;
        if(m[i][j].second==-1) m[i][j].second=0;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if(matrix.empty()||matrix[0].empty()) return res;
        vector<vector<bool>>vis(matrix.size(),vector<bool>(matrix[0].size(),false));
        vector<vector<pair<int,int>>>m(matrix.size(),vector<pair<int,int>>(matrix[0].size(),pair<int,int>(-1,-1)));
        for(int i=0;i<matrix.size();i++) for(int j=0;j<matrix[0].size();j++){
            if(m[i][j].first==-1){
                DFS(vis,matrix,m,i,j);
                vis[i][j]=false;
            }
            if(m[i][j].first==1&&m[i][j].second==1){
                res.push_back(vector<int>(2));
                res.back()[0]=i;
                res.back()[1]=j;
            }
        }
        return res;
    }
};
