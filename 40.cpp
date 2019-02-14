class Solution {
public:
    void DFS(vector<vector<int>>& out,vector<int>& candidates,vector<int>& v,int target,int x){
        if(!target){
            out.push_back(v);
            return;
        }
        for(int i=x+1;i<candidates.size();i++){
            if(i!=x+1&&candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            v.push_back(candidates[i]);
            DFS(out,candidates,v,target-candidates[i],i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>out;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        DFS(out,candidates,v,target,-1);
        return out;
    }
};
