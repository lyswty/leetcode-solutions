class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        int i;
        for(i=1;i<=citations.size();i++) if(citations[i-1]<i) break;
        return i-1;
    }
};
