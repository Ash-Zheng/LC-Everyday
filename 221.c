class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0)return 0;
        int m=matrix[0].size();
        int max=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                matrix[i][j]-='0';
                if(max==0&&matrix[i][j]>0)max=1;
            }
            
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]>0&&matrix[i-1][j-1]>0)
                {
                    //判断是否需要+1
                    int tag=0;
                    int tag1=0;
                    for(int k=1;k<=matrix[i-1][j-1];k++)
                    {
                        if(i-k>=0&&matrix[i-k][j]>0)
                            tag++;
                        else
                            break;
                    }
                    for(int k=1;k<=matrix[i-1][j-1];k++)
                    {
                        if(j-k>=0&&matrix[i][j-k]>0)
                            tag1++;
                        else 
                            break;
                    }
                    tag=min(tag,tag1);
                    matrix[i][j]=1+tag;
                    if(matrix[i][j]>max)
                        max=matrix[i][j];
                }
            }
        }
        return max*max;  
    }
};