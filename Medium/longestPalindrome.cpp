class Solution {
public:
    string rv = "";
    // remove all single terminals(that are not the middle characters)
    // Iterate over all letters for potential centers
    void inject(string sub){
        if(rv.length() < sub.length()){
            rv = sub;
        }
    }
    void checkSingle(string s, int center, int myLen = 1){
        // pos at 1, 1 position needs to be free

        int pos1 = center-myLen;
        int pos2 = center+myLen;
        if(pos1 < 0 || pos2 >= s.length()){
            string sub = s.substr(center-myLen+1, myLen*2-1);
            inject(sub);
            cout << myLen << " : " << sub << " terminate\n";
            return;
        }
        if(s[pos1] == s[pos2]){
            checkSingle(s, center, myLen+1);
        }else{
            string sub = s.substr(center-myLen+1, myLen*2-1);
            inject(sub);
            cout << myLen << " : "  << sub << " diff\n";
        }
    }
    void checkDouble(string s, int center, int myLen = 1){
        // center at first double

        int pos1 = center-myLen;
        int pos2 = center+myLen+1;
        if(s[center] != s[center+1]){
            return;
        }
        if(pos1 < 0 || pos2 >= s.length()){
            string sub = s.substr(center-myLen+1, myLen*2);
            inject(sub);
            cout << myLen << " : " << sub << " terminate\n";
            return;
        }
        if(s[pos1] == s[pos2]){
            checkDouble(s, center, myLen+1);
        }else{
            string sub = s.substr(center-myLen+1, myLen*2);
            inject(sub);
            cout << myLen << " : "  << sub << " diff\n";
        }
    }
    string longestPalindrome(string s) {
        for(int i = 0; i < s.length(); i++){
            int target = s[i];
            checkSingle(s, i);
        }
        cout << endl;
        for(int i = 0; i < s.length()-1; i++){
            int target = s[i];
            checkDouble(s, i);
        }
        return rv;
    }
};
