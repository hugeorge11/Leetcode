# George 10/16
# Get h-index
# most integer where h: at least h entries where value is at least h
# How: 
# 0 > sort, reverse, 
# 1 > if citation value is less than # of >= papers, it is the h-index. 
# 2 > Otherwise, log the largest value of h possible from given # of entries
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        rv = 0
        citations.sort(reverse=-1)
        for i in range(0, len(citations)):
            if(citations[i] <= i+1):
                print(citations[i])
                rv = max(rv, citations[i])
                break
            else:
                val = min(i+1, citations[i])
                print(val)
                rv = max(val, rv)
        print(citations)
        return rv
