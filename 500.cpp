class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string>rows(3),res;
        rows[0]="qwertyuiop",rows[1]="asdfghjkl",rows[2]="zxcvbnm";
        unordered_map<char,int>row;
        for(int i=0;i<3;i++) for(char x:rows[i]){
            row[x]=i;
            row[toupper(x)]=i;
        }
        for(string& word:words){
            bool flag=true;
            for(int i=1;i<word.size();i++) if(row[word[i]]!=row[word[0]]){
                flag=false;
                break;
            }
            if(flag) res.emplace_back(word);
        }
        return res;
    }
};
