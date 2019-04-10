class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>>G(numCourses);
        vector<int>precnt(numCourses,0),res;
        for(auto i:prerequisites){
            G[i.second].push_back(i.first);
            precnt[i.first]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++) if(!precnt[i]) q.push(i);
        while(q.size()){
            int cur=q.front();
            q.pop();
            res.push_back(cur);
            for(int i:G[cur]) if(!--precnt[i]) q.push(i);
        }
        return res.size()==numCourses?res:vector<int>();
    }
};
