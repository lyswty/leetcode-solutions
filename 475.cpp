class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int res=0;
        for(int house:houses){
            auto hit=lower_bound(heaters.begin(),heaters.end(),house);
            if(hit==heaters.end()) res=max(res,house-*(hit-1));
            else if(*hit==house) continue;
            else if(hit==heaters.begin()) res=max(res,*hit-house);
            else{
                int cur=min(*hit-house,house-*(hit-1));
                res=max(cur,res);
            }
        }
        return res;
    }
};
