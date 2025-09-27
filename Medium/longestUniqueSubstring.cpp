// George Hu
// 9/27
// Catapillar Solution
class Solution {
public:
    int rv = 0;
    // push-pop method
    void inject(int len){
        if(len > rv){
            rv = len;
        }
    }
    void runner(string s){
        ;
    }
    int lengthOfLongestSubstring(string s) {
        string buf = "";
        for(int i = 0; i < s.length(); i++){
            char target = s[i];

            auto findMe = find(buf.begin(), buf.end(), target);
            while(findMe != buf.end()){
                buf.erase(buf.begin());
                findMe = find(buf.begin(), buf.end(), target);
            }
            buf.push_back(target);
            inject(buf.length());
            cout << buf << endl;
        }
        return rv;
    }
};
