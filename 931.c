class Solution {
public:
    int best=INT_MAX;
    int length=0;
    int dp[1000][1000]={0};
    
    int cal_min(int n,int m)
    {
        int temp;
        if(m-1<0)
        {
            temp=dp[n+1][m];
            if(dp[n+1][m+1]<temp)
                temp=dp[n+1][m+1];
        }
        else if(m+1>=length)
        {
            temp=dp[n+1][m];
            if(dp[n+1][m-1]<temp)
                temp=dp[n+1][m-1];
        }
        else{
            temp=dp[n+1][m];
            if(dp[n+1][m-1]<temp)
                temp=dp[n+1][m-1];
            if(dp[n+1][m+1]<temp)
            temp=dp[n+1][m+1];
        }
        return temp;
    }

    int minFallingPathSum(vector<vector<int>>& A) {
        length=A.size();
        for(int j=0;j<length;j++)
        {
            dp[length-1][j]=A[length-1][j];
        }
        for(int i=length-2;i>=0;i--)
        {
            for(int j=0;j<length;j++)
            {
                dp[i][j]=A[i][j]+cal_min(i,j);
            }
        }
        
        for(int j=0;j<length;j++)
        {
            if(dp[0][j]<best)
                best=dp[0][j];
        }
        
        return best;
    }
};