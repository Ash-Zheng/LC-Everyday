class Solution {
public:
    int rever=0;
    int merge(vector<int>& nums,int l,int r,vector<int>& tmp)
    {
        if (l >= r) {
            return 0;
        }
        
        int mid=(r+l)/2;
        int inv_count=merge(nums,l,mid,tmp)+merge(nums,mid+1,r,tmp);
        int lp=l,rp=mid+1,p=l;
        while(lp<=mid&&rp<=r)
        {
            if(nums[lp]<=nums[rp])
            {
                tmp[p++]=nums[lp++];
                inv_count+=(rp - (mid + 1));
            }
            else
            {
                tmp[p++]=nums[rp++];
            }
        }
        if(lp<=mid){
            while(lp<=mid)
            {
                tmp[p++]=nums[lp++];
                inv_count+=(rp - (mid + 1));
            }
        }
        else{
            while(rp<=r)
            {
                tmp[p++]=nums[rp++];
            }
        }
        
        for(int i=l;i<=r;i++)
        {
            nums[i]=tmp[i];
        }
        return inv_count;
    }

    int reversePairs(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> tmp(n);
        int k=merge(nums,0,n-1,tmp);
        return k;
    }
};
