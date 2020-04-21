class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>pls;
        int n=nums.size(),cnt=0;
        for(int i=0;i<n;i++)
            if(nums[i]%2==1)
                pls.push_back(i);
        if(pls.size()<k)
            return 0;
        else if(pls.size()==k)
            return (pls[0]+1)*(nums.size()-pls.back());

        pls.push_back(n);
        pls.insert(pls.begin(),-1);
        int p=k+1,lp=1;
        while(p<pls.size())
        {
            cnt+=(pls[lp]-pls[lp-1])*(pls[p]-pls[p-1]);
            p++;
            lp++;
        }
        return cnt;
    }
};