// N: Err: revert var for loop, make problem simpler, double equals, 
class Solution {
public:

    // Implement any-chars
    // omit any# chars
    // but origin s needs to meet end req
    // ? Recurse on the remainder
    // ? Match start and end and then...
    // ? tokenize p by ANYCHARS, s match algo
    // Match front and back alternating. If noMatch, return false
    const char ANY_CHARS = '*';
    const char ANY_CHAR = '?';
    vector<string> charTok(string s, char c){
        vector<string> rv={};
        int myPos = 0;
        string sub = {};
        for(int i  = 0; i < s.length(); i++){
            char target = s[i];
            if(target == c){
                sub = s.substr(myPos, i-myPos);
                if(sub.empty() == false){
                    rv.push_back(sub);
                }
                //myPos = i;
                myPos = i+1; // for omitting delimiter symb
            }
        }
        sub = s.substr(myPos, (s.length())-myPos);
        if(sub.empty() == false){
            rv.push_back(sub);
        }
        return rv;
    }
    bool dice(string &s, string p){
        if(p.length()>s.length())return false;
        // dice more strict(must be in 0 position)
        bool isFound = true;
        int myPos = 0;
        for(int j = 0; j < p.length();j++){
            char patChar = p[j];
            char subChar = s[j];
            if(patChar == ANY_CHAR){
                continue;
            }
            if(patChar != subChar){
                isFound = false;
                break;
            }
        }
        if(isFound == true){
            s = s.substr(p.length());
            cout << "("<< p << ") found.(1)" << endl;
            return true;
        }
        cout << "("<< p << ") not found.(2)" << endl;
        return false;
    }
    bool chop(string &s, string p) {
        if(p.length()>s.length())return false;
        bool isFound = true;
        for(int i = 0; i < (s.length()+1)-p.length(); i++){
            // ?Cannot match with pattern* pointer OR find()
            // -because of ANY_CHAR or overlapping sub
            // -Check for every char
            int myPos = 0;
            for(int j = 0; j < p.length();j++){
                if(i+j >= s.length()){// subChar overflow?
                    return false;
                }
                char patChar = p[j];
                char subChar = s[i+j];
                if(patChar == ANY_CHAR){
                    continue;
                }
                if(patChar != subChar){
                    isFound = false;
                    break;
                }
            }
            if(isFound == true){
                s = s.substr(i+p.length());
                cout << "("<< p << ") found.(3)" << endl;
                return true;
            }
            isFound = true;
            
        }
        cout << "("<< p << ") not found.(4)" << endl;
        return false;
    }
    ////////////////////////////////////////////////
    bool isMatch(string s, string p){
        bool startChop = true, lastChop = true;
        

        vector<string> tokens = charTok(p, ANY_CHARS);// tokenize: *abc*def* -> *abc *def *
        if(p[0] != ANY_CHARS){
            startChop = false;
        }
        if(!p.empty()){
            if(p[p.length()-1] != ANY_CHARS){
                lastChop = false;
            }
        }else{
            lastChop = false;
        }
        if(startChop)cout << "*chop* "; 
        for(auto e: tokens){
            cout << e << ", ";
        }
        if(lastChop)cout << " *chop*";
        cout<<endl<<endl;

        bool leading = startChop, trailing = lastChop;
        string lTok, rTok;
        
        bool omitMe = (tokens.size() >= 2);
        if(!startChop && !tokens.empty()){
            lTok = tokens[0];
            if(dice(s, lTok) == false)return false;
            cout << "-> " << s << endl;
            tokens.erase(tokens.begin());
        }
        if(!lastChop && !tokens.empty()){
            rTok = tokens[tokens.size()-1];
            reverse(s.begin(), s.end());
            reverse(rTok.begin(), rTok.end());
            if(dice(s, rTok) == false)return false;
            cout << "-> " << s << endl;
            reverse(s.begin(), s.end());
            tokens.pop_back();
        }
        
        for(int i = 0; i < (tokens.size()+1)/2; i++){
            int left = i;
            int right = (tokens.size()-1) - i;
            
            lTok = tokens[left];
            leading = true;
            if(chop(s, lTok) == false){
                return false;
            }
            cout << "-> " << s << endl;
            if(left != right){
                rTok = tokens[right];
                trailing = true;
                reverse(s.begin(), s.end());
                reverse(rTok.begin(), rTok.end());
                if(chop(s, rTok) == false){
                    return false;
                }
                reverse(s.begin(), s.end());

                cout << "-> " << s << endl;
            }else{
                cout << endl;
                break;
            }
        }
        if(!s.empty()){
            cout << "remain: " << s << endl;
        }
        bool rv = s.empty() || leading || trailing || omitMe;
        return rv;
    }
};
