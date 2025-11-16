# George Hu 11/15
# N: sliding window, 3 part process of cutting excess, log, clean previous
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        windowArr = []
        mySum = 0
        rv = len(nums)+1# minimum
        for i in range(len(nums)):
            elem = nums[i]
            # incorperate target
            windowArr.append(elem)
            mySum += elem
            #
            if(mySum >= target):
                while(windowArr[0] <= mySum - target):
                    popped = windowArr.pop(0)
                    mySum -= popped
                
                if(len(windowArr) < rv):
                    rv = len(windowArr)
                while(mySum >= target):
                    if(len(windowArr) == 0):
                        break
                    popped = windowArr.pop(0)
                    mySum -= popped
            
        if(rv > len(nums)):
            rv = 0
        return rv
