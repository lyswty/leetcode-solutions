class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return vector<string>();
        string M[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        list<string>q;
        for(int i=0;i<M[digits[0]-'0'].size();i++) q.push_back(string(1,M[digits[0]-'0'][i]));
        int count=q.size();
        for(int i=1;i<digits.size();i++){
            int n=0;
            while(n<count){
                string cur=q.front();
                q.pop_front();
                for(int j=0;j<M[digits[i]-'0'].size();j++) q.push_back(cur+M[digits[i]-'0'][j]);
                n++;
            }
            count=q.size();
        }
        return vector<string>(q.begin(),q.end());
    }
};
