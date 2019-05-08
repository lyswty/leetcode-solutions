class Solution {
public:
    static bool cmp(const pair<string,bool>&a,const pair<string,bool>&b){
        return a.first<b.first;
    }
    bool isend(vector<pair<string,bool>>&x){
        if(x.empty()) return true;
        for(auto i:x) if(!i.second) return false;
        return true;
    }
    bool DFS(unordered_map<string,vector<pair<string,bool>>>&G,vector<string>&cur,vector<string>&res,string i,int n){
        cur.push_back(i);
        if(isend(G[i])){
            if(cur.size()==n){
                res=cur;
                return true;
            }
            return false;
        }
        for(int x=0;x<G[i].size();x++) if(!G[i][x].second){
            G[i][x].second=true;
            if(DFS(G,cur,res,G[i][x].first,n)) return true;
            cur.pop_back();
            G[i][x].second=false;
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<pair<string,bool>>>G;
        for(int i=0;i<tickets.size();i++) G[tickets[i][0]].push_back(pair<string,bool>(tickets[i][1],false));
        for(auto it=G.begin();it!=G.end();it++) sort(it->second.begin(),it->second.end(),cmp);
        vector<string>res,cur;
        DFS(G,cur,res,"JFK",tickets.size()+1);
        return res;
    }
};
