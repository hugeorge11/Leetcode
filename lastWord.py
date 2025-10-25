# George Hu 10/25
# lastWord.py
# N: flip and track first word
class Solution:
    TOKEN = ' '
    def lengthOfLastWord(self, s: str) -> int:
        myStr = s[::-1]
        hasWord = False
        count = 0
        for i in range(0, len(s)):
            targChar = myStr[i]
            if(targChar == self.TOKEN):
                if(hasWord == True):
                    break
            else:
                hasWord = True
                count += 1
        return count
        
