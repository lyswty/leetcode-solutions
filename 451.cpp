class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>cnt;
        auto cmp=[&cnt](char a,char b){
            return cnt[a]>cnt[b];
        };
        for(char x:s) cnt[x]++;
        vector<char>order;
        for(auto it=cnt.begin();it!=cnt.end();it++) order.push_back(it->first);
        sort(order.begin(),order.end(),cmp);
        int i=0,j=0;
        while(i<s.size()){
            s[i++]=order[j];
            if(!--cnt[order[j]]) j++;
        }
        return s;
    }
};
