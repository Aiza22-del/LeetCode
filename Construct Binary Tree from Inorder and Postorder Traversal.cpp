/*
106. Construct Binary Tree from Inorder and Postorder Traversal
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]
 
Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) 
    {
        if (inStart > inEnd || postStart > postEnd) 
        {
            return nullptr;
        }

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        int inRootIndex = inStart;

        while (inRootIndex <= inEnd && inorder[inRootIndex] != rootVal) 
        {
            inRootIndex++;
        }

        int leftTreeSize = inRootIndex - inStart;

        root->left = buildTreeHelper(inorder, postorder, inStart, inRootIndex - 1, postStart, postStart + leftTreeSize - 1);
        root->right = buildTreeHelper(inorder, postorder, inRootIndex + 1, inEnd, postStart + leftTreeSize, postEnd - 1);

        return root;
    }
};


