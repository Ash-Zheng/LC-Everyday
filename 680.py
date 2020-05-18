class Solution:
    def validPalindrome(self, s: str) -> bool:
        p=0
        q=len(s)-1
        if q<=1:
            return 1
        cnt=0
        while p<q:
            if s[p]==s[q]:
                p+=1
                q-=1
            else:
                pp=p
                pq=q-1
                p+=1
                while p<q:
                    if s[p]==s[q]:
                        p+=1
                        q-=1
                    else:
                        cnt+=1
                        break
                if cnt==0:
                    return 1
                while pp<pq:
                    if s[pp]==s[pq]:
                        pp+=1
                        pq-=1
                    else:
                        cnt+=1
                        break
                if cnt==1:
                    return 1
                else:
                    return 0
        return 1