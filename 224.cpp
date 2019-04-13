class Solution {
public:
    int calculate(string s) {
        stack<char>symbol;
        stack<int>num;
        string s2;
        for(char x:s) if(x!=' ') s2+=x;
        for(int i=0;i<s2.size();i++){
            if(s2[i]==' ') continue;
            else if(isdigit(s2[i])){
                int j=i+1;
                while(j<s2.size()&&isdigit(s2[j])) j++;
                int cur=stoi(s2.substr(i,j-i));
                num.push(cur);
                i=j-1;
            }
            else if(s2[i]=='(') symbol.push(s2[i]);
            else if(s2[i]==')'){
                symbol.pop();
                if(symbol.size()&&symbol.top()=='+'){
                    symbol.pop();
                    int a=num.top();
                    num.pop();
                    int b=num.top();
                    num.pop();
                    num.push(a+b);
                }
                if(symbol.size()&&symbol.top()=='-'){
                    symbol.pop();
                    int a=num.top();
                    num.pop();
                    int b=num.top();
                    num.pop();
                    num.push(b-a);
                }
            }
            else if(s2[i]=='+'&&isdigit(s2[i+1])){
                int a=num.top();
                num.pop();
                int j=i+2;
                while(j<s2.size()&&isdigit(s2[j])) j++;
                int b=stoi(s2.substr(i+1,j-i-1));
                num.push(a+b);
                i=j-1;
            }
            else if(s2[i]=='-'&&isdigit(s2[i+1])){
                int a=num.top();
                num.pop();
                int j=i+2;
                while(j<s2.size()&&isdigit(s2[j])) j++;
                int b=stoi(s2.substr(i+1,j-i-1));
                num.push(a-b);
                i=j-1;
            }
            else symbol.push(s2[i]);
        }
        return num.top();
    }
};
