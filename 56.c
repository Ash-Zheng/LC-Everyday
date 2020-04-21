class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        struct cmp{
            bool operator()(const vector<int> a,const vector<int>b)
            {
                return a[0]>b[0];
            }
        };
        
        priority_queue<vector<int>,vector<vector<int>>,cmp> que;
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {
            que.push(intervals[i]); //将所有intervals入优先队列;
        }
        
        
        //3case: 1.a.up<b.bottom 不合并 2.a.up>=b.bottom a.up>b.up 将b删除 3.a.up>=b.bottom a.up<b.up 合并
        int k=0;
        if(!que.empty())
        {
            intervals[k++]=que.top();
            que.pop();
        }
        while(!que.empty())
        {
            vector<int>temp=que.top();
            if(intervals[k-1][1]<temp[0])//case 1
            {
                que.pop();
                intervals[k++]=temp;
            }
            else if(intervals[k-1][1]>=temp[1])//case 2
            {
                que.pop();
                intervals.erase(intervals.end());
            }
            else //case 3
            {
                intervals[k-1][1]=temp[1];
                que.pop();
                intervals.erase(intervals.end());
            }
        }
        return intervals;
    }
};