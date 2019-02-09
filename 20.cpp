class Solution {
public:
    bool isValid(string s) {
        stack<int> S;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') S.push(1);
            else if(s[i]=='[') S.push(2);
            else if(s[i]=='{') S.push(3);
            else if(s[i]==')'){
                if(S.size()&&S.top()==1) S.pop();
                else return false;
            }
            else if(s[i]==']'){
                if(S.size()&&S.top()==2) S.pop();
                else return false;
            }
            else if(s[i]=='}'){
                if(S.size()&&S.top()==3) S.pop();
                else return false;
            }
        }
        if(S.empty()) return true;
        else return false;
    }
};
