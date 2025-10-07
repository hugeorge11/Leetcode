// George Hu 10/7
// gasStationRing.cpp
// N: Convert to Steps
// Check ring from starting position
// decrement loop(add start to route)
// if start added is LESS than int NEEDGAS blockade, continue loop
// NEEDGAS takes continued variables into consideration
// I: Time friction

class Solution {
public:
    int completeRoute(vector<int> steps,
                int myPos){
        int ringSize = steps.size();
        int gasTank = 0;
        for(int i = 0; i < ringSize; i++){
            gasTank += steps[myPos];
            if(gasTank < 0){
                return abs(gasTank);
            }
            (myPos >= ringSize-1) ? myPos = 0 : myPos++;
        }
        return 0;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        vector<int> steps = gas;
        for(int j = 0; j < gas.size(); j++){
            int step = gas[j] - cost[j];
            steps[j] = step;
        }
        int needGas = 0;
        for(int i = steps.size()-1; i >= 0; i--){
            if(steps[i] < needGas){
                needGas -= steps[i];
                continue;
            }
            needGas = completeRoute(steps, i);
            if(needGas == 0){
                return i;
            }
        }
        
        
        return -1;
    }
};
