class Solution:
    def check(self,x):
        if x in {'a','e','i','o','u'}:
            return True
        else:
            return False
    def findTheLongestSubstring(self, s: str) -> int:
        mp=dict()
        pre=0
        result=0
        for p,i in enumerate(s):
            if self.check(i):
                pre=pre^ord(i)
            if pre==0:
                result=p+1
            else:
                if pre not in mp:
                    mp[pre]=p
                else:
                    temp=p-mp[pre]
                    if temp>result:
                        result=temp
        
        return result
