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
    int countSwap(vector<int> &org)
    {
        vector<int> req = org;
        unordered_map<int, int> mp;
        for (int r = 0; r < org.size(); r++)
            mp[org[r]] = r;
        sort(req.begin(), req.end());

        int swaps = 0;
        for (int i = 0; i < org.size(); i++)
        {
            if (org[i] != req[i])
            {
                int old = mp[req[i]];
                mp[org[i]] = old;
                mp[req[i]] = i;
                swap(org[old], org[i]);
                swaps++;
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode *root)
    {
        int swaps = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<int> ele;

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                ele.push_back(node->val);

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            swaps += countSwap(ele);
        }

        return swaps;
    }
};