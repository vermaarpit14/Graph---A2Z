#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool BFS(int num, vector<int> a[], vector<int> &inDeg, vector<int> &vis)
    {
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < inDeg.size(); i++)
        {
            if (inDeg[i] == 0)
            {
                q.push(i);
                cnt += 1;
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
                    cnt += 1;
                }
            }
        }
        return cnt == num;
    }
    bool canFinish(int num, vector<vector<int>> &pre)
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