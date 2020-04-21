class Solution {

public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0)
            return 0;
        int m=grid[0].size();
        pair<int,int> temp;
        queue<pair<int,int>>que;
        vector<vector<int>> seen(n, vector<int>(m));
        const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1'&&seen[i][j]==0)
                {
                    count++;
                    que.emplace(i,j);
                    for(int k=0;k<4;k++)
                    {
                        int ni=i+dirs[k][0];
                        int nj=j+dirs[k][1];
                        if(ni>=0&&ni<n&&nj>=0&&nj<m&&grid[ni][nj]=='1'&&seen[ni][nj]==0)
                        {
                            seen[ni][nj]=1;
                            que.emplace(ni,nj);
                        }
                    }
                    while(!que.empty())
                    {
                        auto [ti,tj]=que.front();
                        que.pop();
                        for(int k=0;k<4;k++)
                        {
                            int ni=ti+dirs[k][0];
                            int nj=tj+dirs[k][1];
                            if(ni>=0&&ni<n&&nj>=0&&nj<m&&grid[ni][nj]=='1'&&seen[ni][nj]==0)
                            {
                                seen[ni][nj]=1;
                                que.emplace(ni,nj);
                            }
                        }
                    }
                }
            }
        }
        return count;
    }  
};