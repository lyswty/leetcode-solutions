class Solution {
public:
    void DFS(string cur,unordered_map<string,bool>&visited,vector<int>&out){
        visited[cur]=true;
        int sum=0;
        for(int i=0;i<cur.size();i++) sum=sum*2+(cur[i]-'0');
        out.push_back(sum);
        if(out.size()==(int)pow(2,cur.size())) return;
        for(int i=0;i<cur.size();i++){
            if(cur[i]=='0') cur[i]='1';
            else cur[i]='0';
            if(!visited[cur]){
                DFS(cur,visited,out);
                if(out.size()==(int)pow(2,cur.size())) return;
                visited[cur]=false;
                out.pop_back();    
            }
            if(cur[i]=='0') cur[i]='1';
            else cur[i]='0';
        }
    }
    vector<int> grayCode(int n) {
        if(!n) return vector<int>(1,0);
        string str;
        for(int i=0;i<n;i++) str+='0';
        vector<int>output;
        unordered_map<string,bool>visited;
        DFS(str,visited,output);
        return output;
    }
};
