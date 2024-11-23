// cpp

// Brute
class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> newBox(n, vector<char>(m, '.'));

        // rotate
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                newBox[j][m - i - 1] = box[i][j];
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < m; j++)
            {
                int bt = i;
                if (newBox[i][j] == '#')
                {
                    while (bt + 1 < n && newBox[bt + 1][j] == '.')
                    {
                        newBox[bt + 1][j] = '#';
                        newBox[bt][j] = '.';
                        bt++;
                    }
                }
            }
        }
        return newBox;
    }
};

// Optimal
class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> newBox(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++)
        {
            int bt = n - 1;
            for (int j = n - 1; j >= 0; j--)
            {
                // newBox[j][m-i-1] = box[i][j]
                if (box[i][j] == '#')
                {
                    newBox[bt][m - i - 1] = '#';
                    bt--;
                }
                else if (box[i][j] == '*')
                {
                    newBox[j][m - i - 1] = '*';
                    bt = j - 1;
                }
            }
        }
        return newBox;
    }
};