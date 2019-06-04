class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res=0;
        for(int i=0;i<points.size();i++){
            unordered_map<long,int>cnt;
            for(int j=0;j<points.size();j++) if(i!=j) cnt[(points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1])]++;
            for(auto it=cnt.begin();it!=cnt.end();it++) res+=it->second*(it->second-1);
        }
        return res;
    }
};
