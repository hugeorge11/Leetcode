// George Hu 10/27
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> rv = {};
        string catStr = "";
        int wideCount = 0;
        for(int i = 0; i < words.size(); i++){
            string target = words[i];
            wideCount += target.length() + 1;
            if(wideCount > maxWidth+1){
                string foo = catStr.substr(0, catStr.length()-1);
                rv.push_back(foo);

                wideCount = target.length()+1;
                catStr = "";
            }
            // loopStart
            catStr += target + " ";
            // loopEnd
        }
        if(catStr.length() > 0){
                string foo = catStr.substr(0, catStr.length()-1);
                rv.push_back(foo);
        }
        // Populate
        for(int i = 0; i < rv.size()-1; i++){
            string target = rv[i];
            
            //cout << ">" << target << "<" <<endl;
            rv[i].resize(maxWidth, 'X');
            int spaces = rv[i].length() - target.length();
            int count = 0;
            int noSpaces = true;
            while(spaces > 0){// Pollenate spaces
                //start
                ;
                if(rv[i][count] == ' '){
                    noSpaces = false;
                    spaces--;
                    rotate(rv[i].begin()+count, rv[i].end()-1, rv[i].end());
                    rv[i][count] = ' ';
                    while(rv[i][count] == ' '){
                        count++;
                        if(count >= rv[i].length()){
                            count = 0;
                            if(noSpaces == true){
                                break;
                            }
                        }
                    }
                }
                //end
                count++;
                if(count >= rv[i].length()){
                    count = 0;
                    if(noSpaces == true){
                        break;
                    }
                }
            }

            if(noSpaces == true){
                for(int j = target.length(); j < maxWidth; j++){
                    rv[i][j] = ' ';
                }
            }
        }
        
        if(rv.size() > 0){
            rv[rv.size()-1].resize(maxWidth, ' ');
        }
        return rv;
    }
};
