#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ladderLength(string s, string t, vector<string> &lis)
    {
        set<string> st;
        for (string x : lis)
            st.insert(x);
        queue<pair<string, int>> q;
        q.push({s, 1});
        while (!q.empty())
        {
            string str = q.front().first;
            int len = q.front().second;
            q.pop();
            if (str == t)
                return len;
            for (int i = 0; i < str.length(); i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    char ch = (int)(j + 97);
                    string temp = str;
                    temp[i] = ch;
                    if (st.find(temp) != st.end())
                    {
                        q.push({temp, len + 1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};