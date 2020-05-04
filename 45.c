class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return 0;
        vector<int> visit(n);
        visit[0]=0;
        queue<int> que;
        que.push(0);
        while(!que.empty())
        {
            int k=que.front();
            que.pop();
            for(int i=k+nums[k];i>=k+1;i--)
            {
                if(i<n&&visit[i]==0)
                {
                    que.push(i);
                    visit[i]=visit[k]+1;
                }
            }
            if(visit[n-1]!=0)break;
        }
        return visit[n-1];
    }
};