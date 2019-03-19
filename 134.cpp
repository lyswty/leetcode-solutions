class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++){
            if(gas[i]>=cost[i]){
                int x,tank=gas[i]-cost[i];
                if(i+1==gas.size()) x=0;
                else x=i+1;
                while(x!=i){
                    tank+=gas[x]-cost[x];
                    if(tank<0) break;
                    if(x+1==gas.size()) x=0;
                    else x++;
                }
                if(tank<0) continue;
                else return i;
            }
        }
        return -1;
    }
};
