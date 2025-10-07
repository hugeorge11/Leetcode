// George Hu 10/6
class Solution {
public:
    int runner(vector<int>nums, int myPos){
        if(myPos == 0)return 0;
        int j;
        for(int i = myPos; i >= 0; i--){// Backwards traverse
            int elem = nums[i];
            if(i+elem >= myPos){
                j = i;
                //cout << i << "(" << elem << "), ";
            }
        }
        //cout << endl << j << "(" << nums[j] << ")" << endl;
        return runner(nums, j)+1;
    }

    int jump(vector<int>& nums) {
        return runner(nums, nums.size()-1);
    }
};
