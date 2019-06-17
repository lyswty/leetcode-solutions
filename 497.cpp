class Solution {
private:
    vector<vector<int>>rects;
    vector<long long>squares;
public:
    Solution(vector<vector<int>>& rects): rects(rects){
        if(rects.size()){
            squares.resize(rects.size());
            squares[0]=(long long)(rects[0][2]-rects[0][0]+1)*(rects[0][3]-rects[0][1]+1);
            for(int i=1;i<rects.size();i++) squares[i]=squares[i-1]+(long long)(rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1);
        }
    }
    
    vector<int> pick() {
        vector<int>res;
        if(rects.empty()) return res;
        int n=lower_bound(squares.begin(),squares.end(),(double)rand()/RAND_MAX*squares.back())-squares.begin();
        res.emplace_back(rects[n][0]+rand()%(rects[n][2]-rects[n][0]+1));
        res.emplace_back(rects[n][1]+rand()%(rects[n][3]-rects[n][1]+1));
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
