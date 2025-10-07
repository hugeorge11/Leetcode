// George Hu 10/7
// overachieverCandy_Bad.cpp
// N: Bad solution
class Solution {
public:
    int sumVector(vector<int> v){
        int sum = 0;
        for(int e : v){
            sum += e;
        }
        return sum;
    }
    vector<int> flatten(vector<int>v){
        // assume least candy indices v[i] = 1;
        if(v.size()<2)return v;
        int most = 1;
        for(int e : v){
            if(e > most){
                most = e;
            }
        }

        vector<int> rv = v; 
        vector<int> prevV = v;
        for(int i = 1; i <= most; i++){

            int changes = 0;
            for(int j = 0; j < prevV.size();j++){
                int val = prevV[j];
                int left = val;
                int right = val;
                if(j > 0){
                    //
                    left = prevV[j-1]+1;
                }else{
                    if(val > prevV[j+1]+1){
                        rv[j] = prevV[j+1]+1;
                        changes++;
                        continue;
                    }
                }
                if(j < prevV.size()-1){
                    //
                    right = prevV[j+1]+1;
                }else{
                    if(val > prevV[j-1]+1){
                        rv[j] = prevV[j-1]+1;
                        changes++;
                        continue;
                    }
                }
                if(val > left && val > right){
                    rv[j] = max(left, right);
                    changes++;
                    continue;
                }
                if(val < left && val > right){
                    rv[j] = right;
                    changes++;
                    continue;
                }
                if(val > left && val < right){
                    rv[j] = left;
                    changes++;
                    continue;
                }
            }
            if(changes == 0){
                break;
            }
            for(int e : prevV){
                cout << e << ", ";
            }cout << endl;
            prevV = rv;
        }
        for(int e : prevV){
            cout << e << ", ";
        }cout << endl;
        return rv;
    }
    void raise(vector<int>& ratings){
        int least = ratings[0];
        for(int i = 0; i < ratings.size(); i++){
            int elem = ratings[i];
            if(elem < least){
                least = elem;
            }
        }
        for(int j = 0; j < ratings.size(); j++){
            ratings[j] -= (least-1);
        }
    }
    vector<int> simplify(vector<int>v){
        vector<int> rv = v;
        rv[0] = 0;
        for(int i = 1; i < v.size(); i++){
            int elem = v[i];
            if(v[i] == v[i-1]){
                rv[i] = rv[i-1];
            }
            if(v[i] > v[i-1]){
                rv[i] = rv[i-1]+1;
            }
            if(v[i] < v[i-1]){
                rv[i] = rv[i-1]-1;
            }
        }
        return rv;
    }

    vector<int> demote(vector<int>v){
        if(v.size() < 2)return v;
        int least = v[0];
        for(int i = 0; i < v.size(); i++){
            int elem = v[i];
            if(elem < least){
                least = elem;
            }
        }
        vector<int> rv = v;
        for(int i = 0; i < v.size(); i++){
            if(i == 0){
                if(v[0] <= v[1]){
                    rv[i] = least;
                }
                continue;
            }
            if(i == v.size()-1){
                if(v[v.size()-1] <= v[v.size()-2]){
                    rv[i] = least;
                }

                continue;
            }
            
            if(v[i] <= v[i-1] && v[i] <= v[i+1]){
                rv[i] = least;
            }
        }
        return rv;
    }
    int candy(vector<int>& ratings) {
        int sum = 0;

        vector<int> v = simplify(ratings);
        cout << "simplify: ";
        for(auto e: v){
            cout << e << ", ";
        }cout << endl;
        v = demote(v);
        cout << "demote: ";
        for(auto e: v){
            cout << e << ", ";
        }cout << endl;
        raise(v);
        
        v = flatten(v);
        

        sum += sumVector(v);
        return sum;
    }
};
