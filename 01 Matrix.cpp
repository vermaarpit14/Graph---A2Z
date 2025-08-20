#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        while (!q.empty())
        {
            int x = q.front().first.first, y = q.front().first.second,
                t = q.front().second;
            q.pop();
            if (x - 1 >= 0 && !vis[x - 1][y])
            {
                q.push({{x - 1, y}, t + 1});
                vis[x - 1][y] = 1;
                ans[x - 1][y] = t + 1;
            }
            if (y - 1 >= 0 && !vis[x][y - 1])
            {
                q.push({{x, y - 1}, t + 1});
                vis[x][y - 1] = 1;
                ans[x][y - 1] = t + 1;
            }
            if (x + 1 < n && !vis[x + 1][y])
            {
                q.push({{x + 1, y}, t + 1});
                vis[x + 1][y] = 1;
                ans[x + 1][y] = t + 1;
            }
            if (y + 1 < m && !vis[x][y + 1])
            {
                q.push({{x, y + 1}, t + 1});
                vis[x][y + 1] = 1;
                ans[x][y + 1] = t + 1;
            }
        }
        return ans;
    }
};