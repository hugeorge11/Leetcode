// George Hu
// 9/27
// customATOI Medium
// Figuring out all the edge cases. 
// DB: Dont use bool op as assignment
class Solution {
public: 
    long long rv = 0;
    int myAtoi(string s) {

        long long min = -(pow(2,31));
        long long max = pow(2, 31)-1;

        // cull whitespace
        while(s[0]-48 == -16){
            s.erase(s.begin());
        }

        // iterate through char
        bool found = false;
        string _s = s;
        for(int i = 0; i < _s.length(); i++){
            int target = _s[i]-48;

            if(target >= 0 && target < 10){
                cout << target << endl;
                found = true;
                rv *= 10;
                rv += target;
                
                if(rv > max){
                    rv = max + 1;
                    break;
                }
            }
            // non-digit or nonterminating '-'/'+' excluded
            if((target > 9 || target < 0)){
                if(found == false && (target == -3 || target == -5)){
                    found = true;
                    continue;
                }
                break;
            }
        }

        // implement negative
        if(_s[0]-48 == -3){
            rv *= -1;
        }
        // implement rounding
        if(rv > max)rv = max;
        if(rv < min)rv = min;
        return rv;
    }
};
