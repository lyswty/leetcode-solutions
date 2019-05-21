class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int total=0,left=INT_MAX,right=INT_MIN,top=INT_MIN,bottom=INT_MAX;
        set<pair<int,int>>vertex;
        for(auto r:rectangles){
            left=min(left,r[0]);
            bottom=min(bottom,r[1]);
            right=max(right,r[2]);
            top=max(top,r[3]);
            total+=(r[3]-r[1])*(r[2]-r[0]);
            if(vertex.find(pair<int,int>(r[0],r[3]))==vertex.end()) vertex.insert(pair<int,int>(r[0],r[3]));
            else vertex.erase(pair<int,int>(r[0],r[3]));
            if(vertex.find(pair<int,int>(r[0],r[1]))==vertex.end()) vertex.insert(pair<int,int>(r[0],r[1]));
            else vertex.erase(pair<int,int>(r[0],r[1]));
            if(vertex.find(pair<int,int>(r[2],r[3]))==vertex.end()) vertex.insert(pair<int,int>(r[2],r[3]));
            else vertex.erase(pair<int,int>(r[2],r[3]));
            if(vertex.find(pair<int,int>(r[2],r[1]))==vertex.end()) vertex.insert(pair<int,int>(r[2],r[1]));
            else vertex.erase(pair<int,int>(r[2],r[1]));
        }
        return vertex.size()==4&&vertex.find(make_pair(left,top))!=vertex.end()&&vertex.find(make_pair(left,bottom))!=vertex.end()&&vertex.find(make_pair(right,top))!=vertex.end()&&vertex.find(make_pair(right,bottom))!=vertex.end()&&total==(right-left)*(top-bottom);
    }
};
