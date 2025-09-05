#include <algorithm>
class Solution {
public:
    void formatWord(string &word){
        sort(word.begin(), word.end());
    }

    vector<char> getCharacters(string word){
        vector<char> rv = {};
        for(int i = 0; i < word.length(); i++){
            char targetC = word[i];
            if(find(rv.begin(), rv.end(), targetC) == rv.end()){
                rv.push_back(targetC);
            }
        }
        sort(rv.begin(), rv.end());
        for(auto elem: rv){
            cout << elem << ", ";
        }
        cout << endl;
        return rv;
    }
    vector<int> getFrequencies(string word){
        vector<int> rv = {};
        char prevC = '\0';
        int count = 0;
        if(word.size() == 0) return rv;

        for(int i = 0; i < word.length(); i++){
            char targetC = word[i];
            count++;
            if(prevC == '\0'){
                prevC = targetC;
                continue;
            }
            if(targetC != prevC){
                rv.push_back(count-1);
                count = 1;
            }
            prevC = targetC;
        }
        rv.push_back(count);
        sort(rv.begin(), rv.end());
        return rv;
    }
    bool closeStrings(string word1, string word2) {
        
        formatWord(word1);
        formatWord(word2);
        cout << word1 << " " << word2 << endl;
        bool returnValue = true;
        if(getCharacters(word1) != getCharacters(word2)){
            cout << "Unmatched characters\n";
            returnValue = false;
        }
        if(getFrequencies(word1) != getFrequencies(word2)){
            cout << "Unmatched frequencies\n";
            returnValue = false;
        }
        return returnValue;
    }
};
