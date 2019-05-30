class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string>q;
        unordered_set<string>b(bank.begin(),bank.end()),vis;
        q.push(start);
        vis.insert(start);
        string last=start,l=last;
        int cnt=0;
        while(q.size()){
            string cur=q.front();
            q.pop();
            if(cur==end) return cnt;
            for(char &x:cur){
                char y=x;
                if(y!='A'){
                    x='A';
                    if(vis.find(cur)==vis.end()&&b.find(cur)!=b.end()){
                        q.push(cur);
                        vis.insert(cur);
                        l=cur;
                    }
                }
                if(y!='C'){
                    x='C';
                    if(vis.find(cur)==vis.end()&&b.find(cur)!=b.end()){
                        q.push(cur);
                        vis.insert(cur);
                        l=cur;
                    }
                }
                if(y!='G'){
                    x='G';
                    if(vis.find(cur)==vis.end()&&b.find(cur)!=b.end()){
                        q.push(cur);
                        vis.insert(cur);
                        l=cur;
                    }
                }
                if(y!='T'){
                    x='T';
                    if(vis.find(cur)==vis.end()&&b.find(cur)!=b.end()){
                        q.push(cur);
                        vis.insert(cur);
                        l=cur;
                    }
                }
                x=y;
            }
            if(last==cur){
                last=l;
                cnt++;
            }
        }
        return -1;
    }
};
