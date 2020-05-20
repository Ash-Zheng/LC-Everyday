class Solution {
public:
    bool check(char x)
    {
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')
            return true;
        else
            return false;
    }
    int findTheLongestSubstring(string s) {
        int n=s.length();
        int result=0;
        unordered_map<int,int> map;
        int pre=0;
        for(int i=0;i<n;i++)
        {
            if(check(s[i]))
            {
                pre=pre^int(s[i]);
            }
            if(pre==0)result=i+1;
            else{
                auto got=map.find(pre);
                if(got==map.end())
                    map.insert({pre,i});
                else{
                    result=i-got->second>result?i-got->second:result;
                }
            }
        }
        return result;
    }
};