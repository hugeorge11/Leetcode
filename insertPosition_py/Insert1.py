class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int prev = 0;
        for(auto e : nums){
            if(e < target){
                prev++;
            }else{
            }
            
        }
        return prev;
    }
};
