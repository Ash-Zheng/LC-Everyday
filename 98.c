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
int tag=0;
long long pre=-2147483649;
void mid_search(TreeNode* root){
    if(root==NULL)return;
    mid_search(root->left);
    if(root->val<=pre)tag=1;
    pre=root->val;
    mid_search(root->right);
}

public:
    bool isValidBST(TreeNode* root) {
        mid_search(root);
        if(tag==0)return true;
        else return false;
    }
};