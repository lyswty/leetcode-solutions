class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i=0;i<tokens.size();i++){
            if(isdigit(tokens[i][0])||(tokens[i][0]=='+'||tokens[i][0]=='-')&&tokens[i].size()>1&&isdigit(tokens[i][1])) s.push(stoi(tokens[i]));
            else{
                int x2=s.top();
                s.pop();
                int x1=s.top();
                s.pop();
                if(tokens[i]=="+") x1+=x2;
                else if(tokens[i]=="-") x1-=x2;
                else if(tokens[i]=="*") x1*=x2;
                else if(tokens[i]=="/") x1/=x2;
                s.push(x1);
            }
        }
        return s.top();
    }
};
