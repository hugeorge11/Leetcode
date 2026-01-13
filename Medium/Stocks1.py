# Anchor Point
# Mid
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        anchor = 0
        mySum = 0
        while(anchor < len(prices)):
            temp = anchor+1
            
            while(temp < len(prices)):
                if(prices[temp] > prices[anchor]):
                    #print(prices[anchor], " and ", prices[temp])
                    mySum += (prices[temp] - prices[anchor])
                    anchor = temp-1
                    break
                else:
                    anchor = temp
                    temp += 1
            
            # end
            anchor += 1

        return mySum
