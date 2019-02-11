class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>out;
        if(words.empty()||!s.length()) return out;
        unordered_map<string,int>cnt;
        for(int i=0;i<words.size();i++) cnt[words[i]]++;
        int n=words[0].length(),l=words.size()*n;
        for(int i=0;i+l<=s.size();i++){
            unordered_map<string,int>residue=cnt;
            bool issubstr=true;
            for(int j=i;j<i+l;j+=n){
                string curword=s.substr(j,n);
                if(residue[curword]) residue[curword]--;
                else{
                    issubstr=false;
                    break;
                }
            }
            if(issubstr) out.push_back(i);
        }
        return out;
    }
};
