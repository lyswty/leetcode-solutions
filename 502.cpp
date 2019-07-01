class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int>heap;
        multiset<pair<int,int>>s;
        for(int i=0;i<Capital.size();i++) s.insert(make_pair(Capital[i],Profits[i]));
        set<pair<int,int>>::iterator last=s.begin();
        while(k){
            for(auto i=last;;i++){
                if(i==s.end()||i->first>W){
                    last=i;
                    break;
                }
                heap.push(i->second);
            }
            if(heap.empty()) break;
            W+=heap.top();
            heap.pop();
            k--;
        }
        return W;
    }
};
