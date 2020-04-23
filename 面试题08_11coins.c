class Solution {
public:
    int waysToChange(int n) {
        int methods[4]={12,4,2,1};
        int coins[4]={1,5,10,25};
        vector<vector<long>> dp(4,vector<long>(n+1));
        for(int i=0;i<4;i++)
            for(int j=0;j<n+1;j++)
            {
                if(i==0)
                {
                        dp[i][j]=1;
                }
                else if(j>=coins[i]){
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        return dp[3][n]%1000000007;
    }
};