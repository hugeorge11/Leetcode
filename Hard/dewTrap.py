# George Hu 10/25
# dewTrap.py
# N: time: O_nlogn
# Used height areas with left and right pointers
# use of hash dict and then sifting algorithm
class Solution:
    def sift(self, left, right, height: List[int]) -> int:
        rv = 0
        for i in range(left+1, right):
            target = height[i]# list is SEQUENTIAL. Range guarenteed to contain CUT BARS
            rv += target
        #print("sifted ", rv, end = ".")
        return rv
    def trap(self, height: List[int]) -> int:
        
        #O_n
        myDict = {}
        for i in range(0, len(height)):# get height map
            target = height[i]
            if target in myDict:
                myDict[target].append(i)
            else:
                myDict[target] = [i]
        #O_nlogn
        newDict = reversed(sorted(myDict))
        #O_n
        mySum = 0
        left = None
        right = None
        for currHeight in newDict:
            # atloop
            if(currHeight == 0):
                break
            # loop
            # Check head and tail of a certain height
            for i in ([0, len(myDict[currHeight])-1] if 0 != len(myDict[currHeight])-1 else [0]):
                # atLoop
                # Jump from loop head to end
                # OMIT walls, but data is in dict
                new = myDict[currHeight][i]
                #print(new, ", ", end = "")
                if left is None:
                    left = new
                    continue
                if right is None:
                    right = max(new, left)
                    left = min(left, new)
                    mySum += (currHeight) * (right - left-1)# exclude one of 2 bars
                    mySum -= self.sift(left, right, height)
                # loop
                if(new < left):# guarenteed that i is unique
                    mySum += currHeight * (left - new-1)# guarenteed that height descends
                    mySum -= self.sift(new, left, height)
                    left = new
                elif(new > right):
                    mySum += currHeight * (new - right-1)
                    mySum -= self.sift(right, new, height)
                    right = new
                else:
                    pass# ignore overlap heights fn
                #print("-> ", mySum)
                # endLoop
            # endLoop
        #print(myDict)
        return mySum
        
        '''
        rv
        lowest
        while lowest > 0
            get highest peaks(highest, lowest)
            declare lowest
            (all others lesser or equal)
            sum = (lowest * i_2 - i_1)
            sum - InsideIndicies
        '''
        '''
        # left-right squeeze
        rv = 0
        # get height map
        myDict = {}
        for i in range(0, len(height)):
            target = height[i]
            while(target > 0):
                if target in myDict:
                    myDict[target].append(i)
                else:
                    myDict[target] = [i]
                target -= 1

        return rv
        for elem in myDict:
            sum = 0
            if(len(myDict[elem]) > 1):
                sum = myDict[elem][len(myDict[elem])-1] - myDict[elem][0] - (len(myDict[elem])-1)
                rv += sum
        return rv
        '''
