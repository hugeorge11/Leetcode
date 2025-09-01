class Solution {
public:
    int uniqueCount = 0;
    int curr;
    int prevUnique;
    int lastPosition = 0;
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        prevUnique = nums[0];
        uniqueCount++;
        for(auto &e : nums){
            curr = e;
            if(curr != prevUnique){
                uniqueCount++;
                lastPosition++;
                nums[lastPosition] = e;
                prevUnique = e;
            }
        }

        cout << endl << uniqueCount << endl;
        return uniqueCount;
    }
};
