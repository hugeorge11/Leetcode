class Solution {
public:
    string output;
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() > 0){
            output = strs[0];
        }
        for(int i = 0; i < strs.size(); i++){
            string targetStr = strs[i];
            for(int j = 0; j < output.length(); j++){
                if(j > targetStr.size()){
                    break;
                }
                char outputChar = output[j];
                char targetChar = targetStr[j];
                if(outputChar != targetChar){
                    output.resize(j);
                }
            }
        }
        return output;
    }
};
