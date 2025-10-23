# George Hu 10/23
# productsO_n.py
# using parallel loops with collections variable
# O_n time complexity
class Solution:
    
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        rv = [1] * len(nums)
        # collection agent for O(n) time:
        collection = 1
        numsLen = len(nums)
        for i in range(0, numsLen):
            rv[i] *= collection
            collection *= nums[i]
        collection = 1
        for i in range(numsLen-1, -1, -1):
            rv[i] *= collection
            collection *= nums[i]
        return rv
