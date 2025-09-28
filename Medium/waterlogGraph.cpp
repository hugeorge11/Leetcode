// George Hu
// 9/27
// waterlogGraph Medium
// Catapillar solution? - NO
// Tips: minimum cap pointers
class Solution {
public:
    int rv = 0;
    void inject(int num){
        cout << num << endl;
        if(num > rv){
            rv = num;
        }
    }
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        while(i != j){
            inject(abs(i-j) * min(height[i], height[j]));
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return rv;
    }
};
