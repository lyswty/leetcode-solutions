class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res=0,fin=0;
        for(int attack:timeSeries){
            res+=attack+duration-max(fin,attack);
            fin=attack+duration;
        }
        return res;
    }
};
