class Solution {
private:
    struct element{
        int val;
        int cnt;
        friend bool operator<(const element &a,const element &b){
            return a.cnt<b.cnt;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,element>mp;
        priority_queue<element>heap;
        for(int i:nums){
            if(mp.find(i)==mp.end()){
                mp[i].val=i;
                mp[i].cnt=1;
            }
            else mp[i].cnt++;
        }
        for(auto it=mp.begin();it!=mp.end();it++) heap.push(it->second);
        vector<int>res;
        while(k--){
            res.push_back(heap.top().val);
            heap.pop();
        }
        return res;
    }
};
