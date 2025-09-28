// George Hu
// 9/27
// reverseInteger Medium
// datatype use of long long instead of int. 
// Queue/Stack pract
class Solution {
public:
    long rv = 0;
    queue<int> myQueue = {};
    int reverse(long long x) {

        long long _x = abs(x);

        while(_x > 0){
            int target = _x % 10;
            myQueue.push(target);
            _x /= 10;
        }
        while(myQueue.size() > 0){
            int qTarget = myQueue.front();
            rv *= 10;
            rv += qTarget;
            myQueue.pop();
        }
        if(rv > (pow(2, 31)-1) || rv < -(pow(2, 31))){
            return 0;
        }

        if(x < 0)rv *= -1;
        return rv;
    }
};
