# shifting in array: bad time complexity(O(n^2))
# George Hu 10/16
class Solution:

    def removeDuplicates(self, nums: List[int]) -> int:
        rv = len(nums)
        prev = None
        dupCount = 0
        i = 0
        prev = None
        while i < len(nums):
            # begin
            curr = nums[i]
            # loop
            if prev is not None:
                if prev == curr:
                    dupCount += 1
                    if(dupCount >= 2): # action
                        print(curr, " print")
                        nums.pop(i)
                        rv -= 1
                        continue # maintain prev and i
                else:
                    dupCount = 0
            # end
            i += 1
            prev = curr
        return rv
