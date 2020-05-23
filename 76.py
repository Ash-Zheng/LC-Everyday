class Solution:
    def minWindow(self, s: str, t: str) -> str:
        def check():
            for i in myset:
                if mydic[i]<=0:
                    return False
            return True

        mydic=dict()
        myset=set()
        l=0
        r=0
        sl=-1
        rl=-1
        mlen=len(s)+3
        for i in t:
            if i in myset:
                mydic[i]-=1
            else:
                mydic[i]=0
            myset.add(i)
        
        while r<len(s):
            if s[r] in myset:
                mydic[s[r]]+=1

            if check():
                print(l,r,0)
                while l<=r:
                    if s[l] in myset:
                        mydic[s[l]]-=1
                    l+=1
                    if not check():
                        print(l,r,1)
                        if r-l+2<mlen:
                            mlen=r-l+2
                            sl=l-1
                            sr=r+1
                        break
            r+=1

        if sl<0:
            return ""
        else:
            return s[sl:sr]
