/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>que;
        queue<int>level;
        vector<vector<int>>result;
        if(root==NULL)return result;
        vector<int>line;
        que.push(root);
        level.push(1);
        int pre=0;
        while(!que.empty())
        {
            TreeNode*p=que.front();
            int temp=level.front();
            que.pop();
            level.pop();
            if(temp!=pre&&!line.empty())
            {
                result.push_back(line);
                line.clear();
                pre=temp;
            }
            line.push_back(p->val);

            if(p->left){
                que.push(p->left);
                level.push(temp+1);
            }
            if(p->right){
                que.push(p->right);
                level.push(temp+1);
            }
        }
        if(!line.empty())
            result.push_back(line);
        return result;
    }
};