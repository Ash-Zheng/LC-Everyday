class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        dp=[0]*len(nums)
        dpm=[0]*len(nums)
        dp[0]=nums[0]
        for i in range(1,len(nums)):
            t=nums[i]*dp[i-1]
            p=nums[i]*dpm[i-1]
            dp[i]=max(t,p,nums[i])
            dpm[i]=min(t,p,nums[i])
        return max(dp)
