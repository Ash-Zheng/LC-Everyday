class Solution {
public:
    bool canJump(vector<int>& nums) {
        int zero=-1,n=nums.size();
        if(n<=1)return true;
        for(int i=n-2;i>=0;i--)
        {
            if(zero<0)//此时目标是寻找0
            {
                if(nums[i]==0)
                    zero=i;
            }
            else
            {
                if(zero-i<nums[i])
                    zero=-1;
            }
        }
        if(zero<0)
            return true;
        else
            return false;
    }
};