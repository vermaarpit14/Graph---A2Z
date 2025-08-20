#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    void DFS(int x, vector<vector<int>> &a, vector<int> &vis)
    {
        vis[x] = 1;
        for (int i = 0; i < a.size(); i++)
        {
            if (!vis[i + 1] && a[x - 1][i] == 1)
                DFS(i + 1, a, vis);
        }
    }
    int findCircleNum(vector<vector<int>> &a)
    {
        int n = a.size(), ans = 0;
        vector<int> vis(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                DFS(i, a, vis);
                ans += 1;
            }
        }
        return ans;
    }
};