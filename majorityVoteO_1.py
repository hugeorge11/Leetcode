# George Hu 10/23
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # Using dict to track each member
        # need to get greatest
        # Use the premise to get O_1 space
        numslen = len(nums)
        #
        prev = None# assume numslen > 0
        count = 0
        for i in range(0, numslen):
            target = nums[i]
            if(prev is not None):
                if(prev == target):
                    count += 1
                else:
                    count -= 1
                    if(count < 0):
                        prev = target
                        count = 0
            else:
                prev = target
        '''
        numslen = len(nums)
        myDict = {}
        for i in range(0, numslen):
            target = nums[i]
            #
            if target not in myDict:
                myDict[target] = 1
            else:
                myDict[target] += 1
            if(myDict[target] > numslen/2):
                return target
        return -1
        '''
        return prev


