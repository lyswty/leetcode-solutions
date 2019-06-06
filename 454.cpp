class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res=0;
        unordered_map<int,int>AplusB;
        for(int a:A) for(int b:B) AplusB[a+b]++;
        for(int c:C) for(int d:D) res+=AplusB[-c-d];
        return res;
    }
};
