// George Hu
// 9/25/2025
// Issue: needed to implement duplication check where each layer of implementation ommitted first (unique characters) and each recursion layer only considered unique integers.
class Solution {
public:
    vector<vector<int>> rv;
    int _target;
    int count = 0;

    // [0,1,1,2,3]
    void runner(vector<int>& nums, vector<int> path = {}, int pos = 0, long sum = 0){
        count++;
        if(path.size() == 3){
            if(pos > nums.size())return;
            long targetSum = _target - sum;

            for(int j = pos;
                j < nums.size();j++){      
                int targetVal = nums[j];
                if(targetVal == targetSum){
                    path.push_back(targetSum);
                    auto pathIn = find(rv.begin(), rv.end(), path);
                    if(pathIn == rv.end()){
                        rv.push_back(path);
                    }
                    break;
                }
            }
            return;
        }
        // Recurse
        for(int i = pos; i < nums.size(); i++){
            if(i > 0 && i > pos){
                if(nums[i - 1] == nums[i]){
                    continue;
                }
            }
            int targetNum = nums[i];
            // if targetNum is positive, following only increases
            if(sum > _target && targetNum > 0){
                return;
            }
            vector<int> targetPath = path;
            targetPath.push_back(targetNum);
            runner(nums, targetPath, i+1, sum + targetNum);
        }
        
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        _target = target;
        sort(nums.begin(), nums.end());
        for(auto e : nums){
            cout << e << " ";
        }
        cout << endl;
        runner(nums);
        cout << count << " runs" << endl;
        return rv;
    }
};
