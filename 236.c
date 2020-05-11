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
    unordered_map<int,TreeNode*> map;
    unordered_set<int>set;
    void search(TreeNode* root,TreeNode* pre)
    {
        if(root==NULL)return;
        map[root->val]=pre;
        search(root->left,root);
        search(root->right,root);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        search(root,NULL);
        while(p!=NULL)
        {
            set.insert(p->val);
            p=map[p->val];
        }
        while(q!=NULL)
        {
            if(set.count(q->val)>0)
            {
                return q;
            }
            q=map[q->val];
        }
        return NULL;
    }
};