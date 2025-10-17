# George Hu 10/17
# merge.py
# N: O(m+n) time complexity through forgo > python sort 
# allocate list of merge
# sort when appending since parameters are sorted
# once array is merged, append the other array
# !: dont use sort-> O(m+n)log(m+n)

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        rv = []
        mIndex = 0
        nIndex = 0
        for i in range(0, n+m):

            if(nIndex == n):
                t1 = nums1[mIndex]
                print(t1)
                rv.append(t1)
                mIndex += 1
                continue
            if(mIndex == m):
                t2 = nums2[nIndex]
                print(t2)
                rv.append(t2)
                nIndex += 1
                continue
            
            t1 = nums1[mIndex]
            t2 = nums2[nIndex]
            if(t1 < t2):
                print(t1)
                rv.append(t1)
                mIndex += 1
            else:
                print(t2)
                rv.append(t2)
                nIndex += 1
        nums1[:] = rv
        return
        
