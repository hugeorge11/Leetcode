class Solution {
public:
    string rv = "";

    string addBinary(string a, string b) {
        if(a.length() < b.length()){
            string t = a;
            a = b;
            b = t;
        }
        while(a.length()>b.length()){
            b.insert(0, "0");
        }
        int carry = 0;
        for(int i = a.length()-1; i >= 0; i--){
            int targetA = (int)a[i]-'0';
            int targetB = 0;
            if(i < b.length()){
                targetB = (int)b[i]-'0';
            }
            
            if(carry ^ targetA ^ targetB){
                rv.insert(0, "1");
            }else{
                rv.insert(0, "0");
            }
            (carry + targetA + targetB > 1) ? carry = 1 : carry = 0;
        }
        if(carry == 1){
            rv.insert(0, "1");
        }
        return rv;
    }
};
