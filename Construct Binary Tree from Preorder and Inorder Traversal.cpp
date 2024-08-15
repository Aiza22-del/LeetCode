/*
105. Construct Binary Tree from Preorder and Inorder Traversal
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]

Constraints:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) 
    {
        if (preStart > preEnd || inStart > inEnd) 
        {
            return NULL;
        }

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = inStart;
        while (inRootIndex <= inEnd && inorder[inRootIndex] != rootVal) 
        {
            inRootIndex++;
        }
        
        int leftTreeSize = inRootIndex - inStart;

        root->left = buildTreeHelper(preorder, inorder, preStart + 1, preStart + leftTreeSize, inStart, inRootIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, preStart + leftTreeSize + 1, preEnd, inRootIndex + 1, inEnd);

        return root;
    }
};


