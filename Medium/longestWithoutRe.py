# George Hu 11/16
# N: Use of 2 pointers in sliding window solution
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left, right = 0,0
        arr = []
        myDict = {}
        rv = 0 # maximum
        for i in range(len(s)):
            elem = s[i]

            right += 1
            if elem not in myDict:
                myDict[elem] = i# first instance
            else:
                while(s[left] != elem):# traverse to reminant
                    del myDict[s[left]]
                    left += 1
                
                left += 1# cut reminant
                myDict[elem] = i# log new

            if(right-left > rv):
                rv = right-left# return
        return rv
