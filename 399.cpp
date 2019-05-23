class Solution {
public:
    double calculate(unordered_map<string,vector<pair<string,double>>>& G,unordered_map<string,bool>& vis,pair<string,double>& x,string end){
        vis[x.first]=true;
        if(x.first==end) return x.second;
        for(auto i:G[x.first]){
            if(!vis[i.first]){
                double res=calculate(G,vis,i,end);
                if(res!=-1.0) return res*x.second;
                vis[i.first]=false;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>G;
        for(int i=0;i<equations.size();i++){
            G[equations[i][0]].push_back(make_pair(equations[i][1],values[i]));
            G[equations[i][1]].push_back(make_pair(equations[i][0],1/values[i]));
        }
        vector<double>res;
        for(auto i:queries){
            if(G.find(i[0])==G.end()||G.find(i[1])==G.end()) res.push_back(-1.0);
            else{
                unordered_map<string,bool>vis;
                auto x=make_pair(i[0],1.0);
                res.push_back(calculate(G,vis,x,i[1]));
            }
        }
        return res;
    }
};
