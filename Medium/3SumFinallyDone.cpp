/*
George Hu 11/15
3Sum
N: Use of find within loop results in nLogn * n instead of the optimal n^2. 
manual repeat skipping required to bypass the need for cpp find
Surprisingly long 
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //
        sort(nums.begin(), nums.end());
        vector<vector<int>> rv = {};
        /////////////////////////////////////////////////////////////////
        for(int left = 0; left < nums.size(); left++){
            if(left > 0){
                if(nums[left] == nums[left-1]){
                    continue;
                }
            }
            int target = -nums[left];
            int right = nums.size()-1;
            int mid = left+1;
            int direction = 1;
            bool cont = false;
            while(mid < right && left < mid){
                if(mid != left+1){
                    while(nums[mid] == nums[mid-1]){
                        mid++;
                        if(right == mid){
                            cont = true;
                            break;
                        }
                    }
                }
                if(right != nums.size()-1){
                    while(nums[right] == nums[right+1]){
                        right--;
                        if(right == mid){
                            cont = true;
                            break;
                        }
                    }
                }
                //cout << left << ": " << mid << ", " << right << endl;
                int mySum = nums[mid] + nums[right];
                if(mySum > target){
                    right--;
                    direction = 0;
                }
                if(mySum < target){
                    mid++;
                    direction = 1;
                }
                if(cont  == true){
                    break;
                }
                if(mySum == target){
                    vector<int> result = {nums[left], nums[mid], nums[right]};
                    rv.push_back(result);
                    if(direction == 0){
                        right--;
                    }else{
                        mid++;
                    }
                }
            }
        }
        return rv;
    }
};
