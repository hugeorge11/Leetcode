class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers)-1
        while(left < right):
            myLeft = numbers[left]
            myRight = numbers[right]
            mySum = myRight + myLeft
            if(mySum == target):
                break
            if(mySum > target):
                right -= 1
            elif(mySum < target):
                left += 1
        return [left+1, right+1]
