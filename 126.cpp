class Solution {
public:
    bool transfer(string a,string b){
        int diff=0;
        for(int i=0;i<a.size();i++) if(a[i]!=b[i]){
            diff++;
            if(diff>1) return false;
        }
        if(diff) return true;
        else return false;
    }
    void DFS(vector<vector<string>>&solutions,unordered_map<string,vector<string>>&path,string x,deque<string>&cur,string beginWord){
        cur.push_front(x);
        if(x==beginWord) solutions.push_back(vector<string>(cur.begin(),cur.end()));
        else for(int i=0;i<path[x].size();i++){
            DFS(solutions,path,path[x][i],cur,beginWord);
            cur.pop_front();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> solutions;
        vector<bool>visited(wordList.size(),false);
        unordered_map<string,vector<string>>path;
        vector<int>length(wordList.size(),INT_MAX);
        deque<string>cur;
        int end=-1;
        for(int i=0;i<wordList.size();i++){
            if(transfer(beginWord,wordList[i])){
                length[i]=1;
                path[wordList[i]].push_back(beginWord);
            }
            if(wordList[i]==endWord) end=i;
        }
        if(end==-1) return solutions;
        if(path[wordList[end]].size()){
            cur.push_back(endWord);
            cur.push_front(beginWord);
            solutions.push_back(vector<string>(cur.begin(),cur.end()));
            return solutions;
        }
        while(true){
            int mini=-1,min=INT_MAX;
            for(int i=0;i<wordList.size();i++) if(!visited[i]&&length[i]<min){
                mini=i;
                min=length[i];
            }
            if(mini==-1||mini==end) break;
            visited[mini]=true;
            for(int i=0;i<wordList.size();i++) if(!visited[i]&&transfer(wordList[mini],wordList[i])){
                if(length[i]>length[mini]+1){
                    length[i]=length[mini]+1;
                    path[wordList[i]].clear();
                    path[wordList[i]].push_back(wordList[mini]);
                }
                else if(length[i]==length[mini]+1) path[wordList[i]].push_back(wordList[mini]);
            }
        }
        DFS(solutions,path,endWord,cur,beginWord);
        return solutions;
    }
};
