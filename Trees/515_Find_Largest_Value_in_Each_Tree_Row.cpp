/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        if (root == NULL)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<int> largest;
        while (!q.empty())
        {
            int n = q.size();
            int maxi = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                maxi = max(maxi, node->val);
                if (node->left != NULL)
                {
                    q.push(node->left);
                }

                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            largest.push_back(maxi);
        }

        return largest;
    }
};