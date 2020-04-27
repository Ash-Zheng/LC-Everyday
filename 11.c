class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int max=0,temp;
        if(n==2)
        {
            if(height[0]>height[1])
                return height[1];
            else
                return height[0];
        }
        for(int i=0;i<n;i++)
        {
            int best;
            for(int j=n-1;j>i;j--)
            {
                if(height[j]>=height[i])
                {
                    best=height[i]*(j-i);
                    break;
                }
            }
            for(int j=0;j<i;j++)
            {
                if(height[i]*(i-j)<best)
                    break;
                else if(height[j]>=height[i])
                {
                    best=height[i]*(i-j);
                    break;
                }
            }
            if(best>max)
                max=best;
        }
        return max;
    }
};
