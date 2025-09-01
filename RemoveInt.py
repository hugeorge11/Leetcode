class Solution {
public:
int output = 0;
    int removeElement(vector<int>& nums, int val) {
        for(auto e = nums.begin(); e != nums.end();){
            if(*e == val){

                //cout << *e << endl;
                nums.erase(e);
            }else{
                output++;
                ++e;
            }
        }
        return output;
    }
};
