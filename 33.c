class Solution {
public:
    int index=-1;
    void binary(vector<int>& nums,int target,int l,int r)
    {
        if(r-l<=3)
        {
            for(int i=l;i<=r;i++)
                if(nums[i]==target)
                    index=i;  
        }
        else{
            int mid=(l+r)>>1;
            if(target>=nums[l]&&target<=nums[mid])
                binary(nums,target,l,mid);
            else if(target<=nums[r]&&target>=nums[mid+1])
                binary(nums,target,mid+1,r);
            else if(nums[mid]>nums[l])
                binary(nums,target,mid+1,r);
            else    
                binary(nums,target,l,mid);
        }
    }

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)return -1;
        binary(nums,target,0,n-1);
        return index;
    }
};