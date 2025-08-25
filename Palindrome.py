class Solution {
public:
    long long reverse = 1;
    int iterations = 0;
    void insertReverse(int x){
        if(x >= 10)return;
        reverse *= 10;
        reverse += x; 
    }
    bool isPalindrome(int x) {
        // Edge Case
        if(x < 0){
            return false;
        }
        // Log iterations floor(half)
        int _x = x;
        while(_x > 0){
            iterations++;
            _x /= 10;
        }
        // Build Reverse
        _x = x;
        while(_x > 0){
            insertReverse(_x % 10);
            _x /= 10;
        }
        // Analyse digits
        //while(x > 0){
        for(int i = 0; i < iterations; i++){
            int aX = x % 10;
            int aReverse = reverse % 10;

            if(aX != aReverse)return false;
            x /= 10;
            reverse /= 10;
        }
        return true;
    }
};
