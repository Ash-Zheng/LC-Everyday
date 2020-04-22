class Solution {
    vector<int> view;
    int max=0;
public:
    void search(TreeNode* root,int depth)
    {
        if(root==NULL)return;
        if(depth>max)
        {
            max=depth;
            view.push_back(root->val);
        }
        search(root->right,depth+1);
        search(root->left,depth+1);
    }

    vector<int> rightSideView(TreeNode* root) 
    {
        search(root,1);
        return view;
    }
};