class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty()) return vector<pair<int,int>>();
        vector<pair<int,int>>res;
        res.push_back(make_pair(buildings[0][0],buildings[0][2]));
        res.push_back(make_pair(buildings[0][1],0));
        for(int i=1;i<buildings.size();i++){
            int j;
            for(j=res.size()-1;res[j].first>=buildings[i][1];j--);
            while(j>=0&&res[j].first>=buildings[i][0]){
                if(buildings[i][2]>res[j].second){
                    int cur=res[j].second;
                    res[j].second=buildings[i][2];
                    if(j+1==res.size()||res[j+1].first>buildings[i][1]) res.insert(res.begin()+j+1,make_pair(buildings[i][1],cur));
                }
                j--;
            }
            if(j>=0&&buildings[i][2]>res[j].second){
                res.insert(res.begin()+j+1,make_pair(buildings[i][0],buildings[i][2]));
                if(j+2==res.size()||res[j+2].first>buildings[i][1]) res.insert(res.begin()+j+2,make_pair(buildings[i][1],res[j].second));
            }
        }
        for(auto it=res.begin()+1;it!=res.end();it++) if(it->second==(it-1)->second){
            it=res.erase(it);
            it--;
        }
        return res;
    }
};
