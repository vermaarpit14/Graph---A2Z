#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> a[graph.size()];
        vector<int> inDeg(graph.size(), 0), ans;
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                a[graph[i][j]].push_back(i);
                inDeg[i] += 1;
            }
        }
        queue<int> q;
        for (int i = 0; i < graph.size(); i++)
        {
            if (inDeg[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for (int x : a[v])
            {
                inDeg[x] -= 1;
                if (inDeg[x] == 0)
                    q.push(x);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};