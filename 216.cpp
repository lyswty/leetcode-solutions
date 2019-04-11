class Solution {
public:
    void DFS(int n,int k,vector<vector<int>>&res,vector<int>&v,int& sum,int x){
        sum+=x;
        v.push_back(x);
        for(int i=x+1;i<=9&&sum+i<=n;i++){
            if(sum+i==n){
                if(v.size()+1==k){
                    v.push_back(i);
                    res.push_back(v);
                    v.pop_back();
                }
                break;
            }
            DFS(n,k,res,v,sum,i);
            v.pop_back();
            sum-=i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum=0;
        vector<vector<int>>res;
        vector<int>v;
        if(!k) return res;
        for(int i=1;i<=9&&i<=10-k;i++){
            DFS(n,k,res,v,sum,i);
            v.pop_back();
            sum=0;
        }
        return res;
    }
};
