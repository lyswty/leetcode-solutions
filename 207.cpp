class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>>G(numCourses);
        vector<int>precnt(numCourses,0);
        for(auto i:prerequisites){
            G[i.second].push_back(i.first);
            precnt[i.first]++;
        }
        int cnt=0;
        queue<int>q;
        for(int i=0;i<numCourses;i++) if(!precnt[i]) q.push(i);
        while(q.size()){
            int cur=q.front();
            q.pop();
            cnt++;
            for(int i:G[cur]) if(!--precnt[i]) q.push(i);
        }
        return cnt==numCourses;
    }
};
