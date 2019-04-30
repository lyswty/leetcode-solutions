class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>G(n);
        vector<int>es(n,0),res;
        unordered_set<int>delvertex;
        for(auto edge:edges){
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
            es[edge[0]]++;
            es[edge[1]]++;
        }
        while((int)delvertex.size()<n-2){
            vector<int>thisturn;
            for(int i=0;i<n;i++) if(es[i]==1){
                delvertex.insert(i);
                thisturn.push_back(i);
                es[i]--;
            }
            for(int i:thisturn) for(int j:G[i]) if(delvertex.find(j)==delvertex.end()) es[j]--;
        }
        for(int i=0;i<n;i++) if(delvertex.find(i)==delvertex.end()) res.push_back(i);
        return res;
    }
};
