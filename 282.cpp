class Solution {
public:
    vector<string>res;
    string out;
    void DFS(const string &num,long long last,long long cur,int target,int j){
        if(j>=num.size()&&cur==target) res.push_back(out);
        else{
            for(int i=j+1;i<=num.size();i++){
                string n1=num.substr(j,i-j);
                if(n1.size()>1&&n1[0]=='0') return;
                long long N1=stoll(n1);
                if(out.size()>0){
                    int ol=out.length();
                    out+='+';
                    out+=n1;
                    DFS(num,N1,cur+N1,target,i);
                    out=out.substr(0,ol);
                    out+='-';
                    out+=n1;
                    DFS(num,-N1,cur-N1,target,i);
                    out=out.substr(0,ol);
                    out+='*';
                    out+=n1;
                    DFS(num,last*N1,(cur-last)+last*N1,target,i);
                    out=out.substr(0,ol);
                }
                else{
                    out=n1;
                    DFS(num,N1,N1,target,i);
                    out.clear();
                }
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        if(num.empty()) return res;
        DFS(num,0,0,target,0);
        return res;
    }
};
