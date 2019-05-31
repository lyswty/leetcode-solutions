class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int,int>>v;
        vector<int>res;
        for(int i=0;i<intervals.size();i++) v.push_back(pair<int,int>(intervals[i][0],i));
        stable_sort(v.begin(),v.end());
        for(int i=0;i<intervals.size();i++){
            auto it=lower_bound(v.begin(),v.end(),pair<int,int>(intervals[i][1],-1));
            if(it!=v.end()) res.push_back(it->second);
            else res.push_back(-1);
        }
        return res;
    }
};
