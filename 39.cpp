class Solution {
public:
    void DFS(vector<vector<int>>& out,vector<int>& candidates,vector<int>& v,int target,int x){
        if(!target){
            out.push_back(v);
            return;
        }
        for(int i=x;i<candidates.size();i++){
            if(candidates[i]>target) break;
            v.push_back(candidates[i]);
            DFS(out,candidates,v,target-candidates[i],i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>out;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        DFS(out,candidates,v,target,0);
        return out;
    }
};
