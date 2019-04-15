class Solution {
public:
    int calculate(string s) {
        string S;
        for(char x:s) if(x!=' ') S+=x;
        stack<int>nums;
        stack<char>ops;
        for(int i=0;i<S.size();i++){
            if(isdigit(S[i])){
                int j;
                for(j=i+1;j<S.size()&&isdigit(S[j]);j++);
                int n=stoi(S.substr(i,j-i));
                nums.push(n);
                i=j-1;
            }
            else if(S[i]=='*'){
                int j;
                for(j=i+2;j<S.size()&&isdigit(S[j]);j++);
                int n2=stoi(S.substr(i+1,j-1)),n1=nums.top();
                nums.pop();
                n2*=n1;
                nums.push(n2);
                i=j-1;
            }
            else if(S[i]=='/'){
                int j;
                for(j=i+2;j<S.size()&&isdigit(S[j]);j++);
                int n2=stoi(S.substr(i+1,j-1)),n1=nums.top();
                nums.pop();
                n1/=n2;
                nums.push(n1);
                i=j-1;
            }
            else{
                if(ops.size()){
                    int n2=nums.top();
                    nums.pop();
                    int n1=nums.top();
                    nums.pop();
                    if(ops.top()=='+') n1+=n2;
                    else n1-=n2;
                    ops.pop();
                    nums.push(n1);
                }
                ops.push(S[i]);
            }
        }
        if(ops.size()){
            int n2=nums.top();
            nums.pop();
            int n1=nums.top();
            nums.pop();
            if(ops.top()=='+') n1+=n2;
            else n1-=n2;
            ops.pop();
            nums.push(n1);
        }
        return nums.top();
    }
};
