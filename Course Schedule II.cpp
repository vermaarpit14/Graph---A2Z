#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> BFS(int num, vector<int> a[], vector<int> &inDeg, vector<int> &vis)
    {
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < inDeg.size(); i++)
        {
            if (inDeg[i] == 0)
            {
                q.push(i);
                ans.push_back(i);
                vis[i] = 1;
            }
        }
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int x : a[v])
            {
                inDeg[x] -= 1;
                if (inDeg[x] == 0 && !vis[x])
                {
                    vis[x] = 1;
                    q.push(x);
                    ans.push_back(x);
                }
            }
        }
        if (ans.size() == num)
            return ans;
        return {};
    }
    vector<int> findOrder(int num, vector<vector<int>> &pre)
    {
        int n = pre.size();
        vector<int> a[num];
        vector<int> inDeg(num, 0);
        for (auto p : pre)
        {
            int x = p[0], y = p[1];
            a[y].push_back(x);
            inDeg[x] += 1;
        }
        vector<int> vis(num, 0);
        return BFS(num, a, inDeg, vis);
    }
};