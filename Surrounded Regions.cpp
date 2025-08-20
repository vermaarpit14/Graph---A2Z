#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void DFS(int i, int j, int n, int m, vector<vector<char>> &a, vector<vector<int>> &vis)
    {
        if (i < n && j < m && i >= 0 && j >= 0 && a[i][j] == 'O')
        {
            if (i + 1 < n && a[i + 1][j] == 'O' && !vis[i + 1][j])
            {
                vis[i + 1][j] = 1;
                DFS(i + 1, j, n, m, a, vis);
            }
            if (j + 1 < m && a[i][j + 1] == 'O' && !vis[i][j + 1])
            {
                vis[i][j + 1] = 1;
                DFS(i, j + 1, n, m, a, vis);
            }
            if (i - 1 >= 0 && a[i - 1][j] == 'O' && !vis[i - 1][j])
            {
                vis[i - 1][j] = 1;
                DFS(i - 1, j, n, m, a, vis);
            }
            if (j - 1 >= 0 && a[i][j - 1] == 'O' && !vis[i][j - 1])
            {
                vis[i][j - 1] = 1;
                DFS(i, j - 1, n, m, a, vis);
            }
        }
    }
    void solve(vector<vector<char>> &a)
    {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
        {
            if (a[0][i] == 'O' && !vis[0][i])
            {
                vis[0][i] = 1;
                DFS(0, i, n, m, a, vis);
            }
            if (a[n - 1][i] == 'O' && !vis[n - 1][i])
            {
                vis[n - 1][i] = 1;
                DFS(n - 1, i, n, m, a, vis);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i][0] == 'O' && !vis[i][0])
            {
                vis[i][0] = 1;
                DFS(i, 0, n, m, a, vis);
            }
            if (a[i][m - 1] == 'O' && !vis[i][m - 1])
            {
                vis[i][m - 1] = 1;
                DFS(i, m - 1, n, m, a, vis);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 'O' && vis[i][j])
                    a[i][j] = 'A';
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 'O')
                    a[i][j] = 'X';
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 'A')
                    a[i][j] = 'O';
            }
        }
    }
};