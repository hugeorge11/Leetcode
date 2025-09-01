class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size()-1;

        if(target <= nums[left]){
            return 0;
        }
        if(target > nums[right]){
            return nums.size();
        }
        for(int i = 0; 
            (right - left) > 1; i++){
            int mid = (right - left)/2 + left;
            if(nums[mid] == target){
                return mid;
            }
            if(i % 2 == 1){
                if(nums[mid] < target){
                    cout << "left shift to";
                    left = mid;
                    cout << mid << endl;    
                }
            }else{
                if(nums[mid] > target){
                    cout << "right shift to ";
                    right = mid;
                    cout << mid << endl;
                }
            }
        }
        return right;
    }
};
