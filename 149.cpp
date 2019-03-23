/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size()<3) return points.size();
        int max=2;
        bool flag=false;
        for(int i=0;i<points.size();i++) for(int j=i+1;j<points.size();j++){
            if(points[i].x==points[j].x&&points[i].y==points[j].y) continue;
            flag=true;
            int cur=2;
            for(int k=0;k<points.size();k++) if(k!=i&&k!=j&&(long)(points[i].x-points[j].x)*(points[k].y-points[j].y)==(long)(points[i].y-points[j].y)*(points[k].x-points[j].x)) cur++;
            if(cur>max) max=cur;
        }
        if(!flag) return points.size();
        return max;
    }
};
