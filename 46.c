class Solution {
public:
    vector<vector<int>> result;
    void search(vector<int> nums,vector<int> visit,vector<int> list,int n,int p)
    {
        visit[n]=1;
        list[p]=nums[n];
        if(p==nums.size()-1)
            result.push_back(list);
        else
        {
            for(int i=0;i<nums.size();i++)
                if(visit[i]==0)
                    search(nums,visit,list,i,p+1);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> visit(n);
        vector<int> list(n);
        for(int i=0;i<n;i++)
        {
            search(nums,visit,list,i,0);
        }
        return result;
    }
};