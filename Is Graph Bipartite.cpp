#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool DFS(int i, int n, vector<vector<int>> &a, vector<int> &vis, int last)
    {
        vis[i] = last;
        for (auto v : a[i])
        {
            if (vis[v] == -1)
            {
                if (!DFS(v, n, a, vis, 1 - last))
                    return false;
            }
            else if (vis[v] == vis[i])
            {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &a)
    {
        int n = a.size();
        vector<int> vis(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == -1)
            {
                if (!DFS(i, n, a, vis, 0))
                    return false;
            }
        }
        return true;
    }
};
