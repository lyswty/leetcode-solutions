class Solution {
public:
    struct numpair{
        int a,b;
        numpair(){}
        numpair(int a,int b):a(a),b(b){}
        friend bool operator<(const numpair &a,const numpair &b){
            return a.a+a.b>b.a+b.b;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<numpair>heap;
        for(int i:nums1) for(int j:nums2) heap.push(numpair(i,j));
        vector<vector<int>>res;
        while(heap.size()&&res.size()<k){
            vector<int>cur;
            cur.push_back(heap.top().a);
            cur.push_back(heap.top().b);
            res.push_back(cur);
            heap.pop();
        }
        return res;
    }
};
