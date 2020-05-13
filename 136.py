class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        x=nums[0]
        for i in nums[1:]:
            x=x^i
        return x
