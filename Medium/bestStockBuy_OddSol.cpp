// George Hu 10/6
// bestStockBuy_OddSol.cpp
// N: 
class Solution {
public:
    
    int maxDiff(vector<int> val){

        for(auto e:val){
            cout << e << ", ";
        }cout << endl;
        int maxGain = 0;
        vector<int>pos = {0,0};
        for(int i = 0; i < val.size(); i++){
            for(int j = val.size()-1; j >= i ; j--){
                int diff = val[j] - val[i];
                if(diff>0){
                    if(diff > maxGain){
                        maxGain = diff;
                        
                        pos = {i, j};
                    }
                }
            }
        }
        if(maxGain == 0){
            cout << "end\n";
            return 0;
        }

        vector<int> sub;
        // Find Difference Before
        sub.assign(val.begin(), val.begin()+pos[0]);
        cout << "before ";
        maxGain += maxDiff(sub);
        // Find Difference within max gain
        sub.assign(val.begin()+pos[0]+1, val.begin()+pos[1]);
        reverse(sub.begin(), sub.end());
        cout << "nested ";
        maxGain += maxDiff(sub);
        // Find Difference After
        sub.assign(val.begin()+pos[1], val.end());
        cout << "after ";
        maxGain += maxDiff(sub);

        

        return maxGain;
    }
    int maxProfit(vector<int>& prices) {
        return maxDiff(prices);
    }
};
