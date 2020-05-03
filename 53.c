class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>0)
                nums[i]=nums[i-1]+nums[i];
            else
                nums[i]=nums[i];

            if(nums[i]>max)
                max=nums[i];
        }
        return max;
    }
};