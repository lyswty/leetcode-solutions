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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool>visited(wordList.size(),false);
        vector<int>length(wordList.size(),INT_MAX);
        int end=-1;
        for(int i=0;i<wordList.size();i++){
            if(transfer(beginWord,wordList[i])) length[i]=1;
            if(wordList[i]==endWord) end=i;
        }
        if(end==-1) return 0;
        if(length[end]==1) return 2;
        while(true){
            int mini=-1,min=INT_MAX;
            for(int i=0;i<wordList.size();i++) if(!visited[i]&&length[i]<min){
                mini=i;
                min=length[i];
            }
            if(mini==-1||mini==end) break;
            visited[mini]=true;
            for(int i=0;i<wordList.size();i++) if(!visited[i]&&length[i]>length[mini]+1&&transfer(wordList[mini],wordList[i])) length[i]=length[mini]+1;
        }
        if(length[end]==INT_MAX) return 0;
        return length[end]+1;
    }
};
