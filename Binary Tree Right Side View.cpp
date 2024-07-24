/*
199. Binary Tree Right Side View
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,null,3]
Output: [1,3]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> temp;
        if (!root) 
        {
            return temp;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) 
        {
            int qLength = q.size();
            for (int i = 0; i < qLength; i++) 
            {
                TreeNode* node = q.front();
                q.pop();

                if (i == qLength - 1) 
                {
                    temp.push_back(node->val);
                }
                if (node->left) 
                {
                    q.push(node->left);
                }
                if (node->right) 
                {
                    q.push(node->right);
                }
            }
        }
        return temp;
    }
};

