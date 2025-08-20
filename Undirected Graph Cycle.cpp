#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isCycle(int n, vector<vector<int>> &grid)
    {
        vector<vector<int>> adj(n);
        for (auto &x : grid)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> vis(n, 0);
        for (int start = 0; start < n; start++)
        {
            if (!vis[start])
            {
                queue<pair<int, int>> q;
                q.push({start, -1});
                vis[start] = 1;

                while (!q.empty())
                {
                    int curr = q.front().first, par = q.front().second;
                    q.pop();
                    for (int nei : adj[curr])
                    {
                        if (vis[nei] && nei != par)
                            return true;
                        if (!vis[nei])
                        {
                            vis[nei] = 1;
                            q.push({nei, curr});
                        }
                    }
                }
            }
        }
        return false;
    }
};
