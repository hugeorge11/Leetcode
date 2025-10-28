# George Hu 10/28
# stocks1.py
# N: Weird queue list algo,
# heads needs to be least, move head pointer to least, compare in loop
class Solution:

    def maxProfit(self, prices: List[int]) -> int:
        rv = 0
        mySum = 0

        head = 0
        stack = []
        for elem in prices:
            stack.append(elem)
            while(stack[head] > elem):
                head += 1
            gain = stack[len(stack)-1] - stack[head]
            if(gain > rv):
                rv = gain
            #print(stack[head:])

        while(head < len(stack)-1):
            
            gain = stack[len(stack)-1] - stack[head]
            if(gain > rv):
                rv = gain
            head += 1
        return rv
            
