#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &a, int sr, int sc, int c2)
    {
        int n = a.size(), m = a[0].size(), c1 = a[sr][sc];
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        a[sr][sc] = c2;
        vis[sr][sc] = 1;
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (x - 1 >= 0 && !vis[x - 1][y] && a[x - 1][y] == c1)
            {
                q.push({x - 1, y});
                vis[x - 1][y] = 1;
                a[x - 1][y] = c2;
            }
            if (y - 1 >= 0 && !vis[x][y - 1] && a[x][y - 1] == c1)
            {
                q.push({x, y - 1});
                vis[x][y - 1] = 1;
                a[x][y - 1] = c2;
            }
            if (x + 1 < n && !vis[x + 1][y] && a[x + 1][y] == c1)
            {
                q.push({x + 1, y});
                vis[x + 1][y] = 1;
                a[x + 1][y] = c2;
            }
            if (y + 1 < m && !vis[x][y + 1] && a[x][y + 1] == c1)
            {
                q.push({x, y + 1});
                vis[x][y + 1] = 1;
                a[x][y + 1] = c2;
            }
        }
        return a;
    }
};