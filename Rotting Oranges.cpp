#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size(), ans = 0;
        queue<vector<int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 2)
                    q.push({i, j, 0});
            }
        }
        vector<vector<int>> vis(n, vector<int>(m, 0));
        while (!q.empty())
        {
            vector<int> temp = q.front();
            q.pop();
            int x = temp[0], y = temp[1], t = temp[2];
            if (x - 1 >= 0 && !vis[x - 1][y] && a[x - 1][y] == 1)
            {
                vis[x - 1][y] = 1;
                q.push({x - 1, y, t + 1});
                ans = max(ans, t + 1);
            }
            if (y - 1 >= 0 && !vis[x][y - 1] && a[x][y - 1] == 1)
            {
                vis[x][y - 1] = 1;
                q.push({x, y - 1, t + 1});
                ans = max(ans, t + 1);
            }
            if (x + 1 < n && !vis[x + 1][y] && a[x + 1][y] == 1)
            {
                vis[x + 1][y] = 1;
                q.push({x + 1, y, t + 1});
                ans = max(ans, t + 1);
            }
            if (y + 1 < m && !vis[x][y + 1] && a[x][y + 1] == 1)
            {
                vis[x][y + 1] = 1;
                q.push({x, y + 1, t + 1});
                ans = max(ans, t + 1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && a[i][j] == 1)
                    return -1;
            }
        }
        return ans;
    }
};