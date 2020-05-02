class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lp=0,rp=0,max=0;
        unordered_set<char> list;
        while(rp<s.length())
        {
            int tag=-1;
            for(int i=lp;i<rp;i++)
            {
                if(s[i]==s[rp])
                {
                    tag=i;
                    break;
                }
            }
            if(tag==-1)
            {
                rp++;
                if(rp-lp>max)
                    max=rp-lp;
            }
            else
            {
                lp=tag+1;
                rp++;
            }
        }
        return max;
    }
};