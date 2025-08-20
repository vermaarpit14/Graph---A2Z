#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string s, string t, vector<string>& lis) {
        unordered_set<string> dict(lis.begin(), lis.end());
        vector<vector<string>> ans;
        if (!dict.count(t)) return ans;
        unordered_map<string, vector<string>> parent;
        unordered_set<string> currLevel, nextLevel;
        queue<string> q;
        q.push(s);
        currLevel.insert(s);
        bool found = false;
        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> visitedThisLevel;
            while (sz--) {
                string word = q.front(); q.pop();
                string orig = word;
                for (int i = 0; i < word.size(); i++) {
                    char old = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (!dict.count(word)) continue;
                        if (!currLevel.count(word)) {
                            if (!visitedThisLevel.count(word)) {
                                q.push(word);
                                visitedThisLevel.insert(word);
                            }
                            parent[word].push_back(orig);
                        }
                        if (word == t) found = true;
                    }
                    word[i] = old;
                }
            }
            for (auto& w : visitedThisLevel) dict.erase(w);
            currLevel = visitedThisLevel;
        }
        if (!found) return ans;
        vector<string> path = {t};
        backtrack(t, s, parent, path, ans);
        return ans;
    }

    void backtrack(string word, string start,
                   unordered_map<string, vector<string>>& parent,
                   vector<string>& path,
                   vector<vector<string>>& ans) {
        if (word == start) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        for (auto& p : parent[word]) {
            path.push_back(p);
            backtrack(p, start, parent, path, ans);
            path.pop_back();
        }
    }
};
