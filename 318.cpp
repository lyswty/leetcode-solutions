class Solution {
public:
    int maxProduct(vector<string>& words) {
        int max=0;
        vector<int>Hash(words.size(),0);
        for(int i=0;i<words.size();i++) for(int j=0;j<words[i].size();j++) Hash[i]|=1<<(words[i][j]-'a');
        for(int i=0;i<words.size();i++) for(int j=i+1;j<words.size();j++) if((Hash[i]&Hash[j])==0&&words[i].size()*words[j].size()>max) max=words[i].size()*words[j].size();
        return max;
    }
};
