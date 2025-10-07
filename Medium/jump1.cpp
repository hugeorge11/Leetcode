// George Hu 10/6
// jump1.cpp
// N: 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int myPos = nums.size()-1;
        int canPass = false;
        while(myPos > 0){
            canPass = false;
            for(int i = 0; i < myPos; i++){
                int elem = nums[i];
                if(i + elem >= myPos){
                    myPos = i;
                    canPass = true;
                    cout << i << "(" << elem << "), ";
                    break;
                }
            }
            if(canPass == false){
                return false;
            }
        }
        
        return true;//runner(nums, nums.size()-1);
    }
};
