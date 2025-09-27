// George Hu
// 9/27
// Medium
// Solve: Tracking iteration pattern for zigzag and mapping prac

class Solution {
public:
    string rv = "";
    map<tuple<int, int>, char> myMap;

    // First col: n height, j = 0
    // (Diagonal: n - 2 columns) 
    // Diag col: row = n - j
    // 
    // From i -> rv.pos:
    // priority: row >> col
    //lesser row, lesser column


    string convert(string s, int numRows) {
        int myRow = 0;
        int myCol = 0;
        int downwards = true;
        for(int i = 0; i < s.length(); i++){
            char target = s[i];
            tuple<int, int> myPos = {myRow, myCol};
            myMap[myPos] = target;

            if(myRow == numRows-1){
                downwards = false;
            }
            if(myRow == 0){
                downwards = true;
            }

            if(downwards == true){
                myRow++;
            }else{
                myCol++;
                myRow--;
            }
        }
        for(auto &e : myMap){
            auto val = e.first;
            //cout << get<0>(val) << ", " << get<1>(val) << " : " << e.second << endl;
            //cout << e.second << endl;
            rv.push_back(e.second);
        }
        return rv;
    }
};
