#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void f(int i, int n, vector<vector<int>> &graph, vector<int> &vis,
           vector<int> &curr, vector<vector<int>> &ans)
    {
        if (i == n - 1)
        {
            ans.push_back(curr);
            return;
        }
        int cnt = 0;
        for (int x : graph[i])
        {
            if (!vis[x])
            {
                vis[x] = 1;
                curr.push_back(x);
                f(x, n, graph, vis, curr, ans);
                vis[x] = 0;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> vis(n, 0), curr;
        vector<vector<int>> ans;
        curr.push_back(0);
        vis[0] = 1;
        f(0, n, graph, vis, curr, ans);
        return ans;
    }
};