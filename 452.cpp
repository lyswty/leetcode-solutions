class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(),points.end(),cmp);
        int res=1,end=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>end){
                res++;
                end=points[i][1];
            }
            else if(points[i][1]<end) end=points[i][1];
        }
        return res;
    }
};
