class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        if (n < 2)
            return 1;
        vector<vector<int>> adj(n);
        vector<int> degree(n);
        vector<long long> newValues(values.begin(), values.end());

        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u] += 1;
            degree[v] += 1;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 1)
                q.push(i);
        }

        int validComponents = 0;
        while (!q.empty())
        {

            int curIdx = q.front();
            q.pop();
            degree[curIdx] -= 1;

            long long addValue = newValues[curIdx];
            if (newValues[curIdx] % k == 0)
            {
                addValue = 0;
                validComponents += 1;
            }

            for (auto neighbour : adj[curIdx])
            {
                if (degree[neighbour] > 0)
                {
                    newValues[neighbour] += addValue;
                    degree[neighbour]--;
                    if (degree[neighbour] == 1)
                        q.push(neighbour);
                }
            }
        }

        return validComponents;
    }
};