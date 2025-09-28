# George Hu
# 9/27
# romanInt.py
# dict constant with concatenated string analysis
class Solution:
    global SYMBOLS
    SYMBOLS = {'M':1000, 'D':500,'C':100,'L':50,'X':10,'V':5,'I':1}
    def intToRoman(self, num: int) -> str:
        rv = ""
        prev = None
        prevprev = None
        for key, val in SYMBOLS.items():
            count = 0
            conStr = ""
            while(num >= val):
                conStr += key
                num -= val
            if prev is not None:
                if(len(conStr) >= 4):
                    count = 4-(len(conStr)-1)
                    conStr = (count * key) + prev
                    if(len(rv)>0):
                        if(rv[len(rv)-1] == prev):
                            rv = rv[:len(rv)-1]
                            conStr = conStr[:len(conStr)-1]
                            conStr += prevprev
                    
            rv += conStr
            print(f"{conStr}", end=' ')
            conStr = ""
            prevprev = prev
            prev = key
            
        return rv
