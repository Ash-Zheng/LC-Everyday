# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    pre=[]
    pls=0
    lens=0
    def helper(self,List,root):
        n=len(List)
        if self.pls<self.lens:
            k=self.pre[self.pls]
            self.pls+=1
            node=TreeNode(k)
            for i,j in enumerate(List):
                if j==k:
                    if i>0:
                        node.left=self.helper(List[0:i],node)
                    if n>i+1:
                        node.right=self.helper(List[i+1:n],node)
            return node
        return None

    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        n=len(preorder)
        if n==0:
            return None
        self.lens=n
        self.pre=preorder
        root=TreeNode(preorder[0])
        k=preorder[self.pls]
        for i,j in enumerate(inorder):
            if j == k:
                self.pls+=1
                if i>0:
                    root.left=self.helper(inorder[0:i],root)
                if n>i+1:
                    root.right=self.helper(inorder[i+1:n],root)
        return root
        