/*
530. Minimum Absolute Difference in BST
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree. 

Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1

Constraints:
The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105
*/

class Solution {
public:
    int minDifference = INT_MAX;
    int prev = -1;

    void inOrderTraversal(TreeNode* root) 
    {
        if (!root) 
        {
            return;
        }

        inOrderTraversal(root->left);
        if (prev != -1) 
        {
            minDifference = min(minDifference, root->val - prev);
        }
        prev = root->val;
        inOrderTraversal(root->right);
    }

    int getMinimumDifference(TreeNode* root) 
    {
        inOrderTraversal(root);
        return minDifference;
    }
};

