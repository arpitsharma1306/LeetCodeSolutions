#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> st;

    void addOperation(const string &node, int a, queue<string> &q) {
        string temp = node;
        for (int i = 1; i < (int)node.size(); i += 2) {
            int digit = (node[i] - '0' + a) % 10;
            temp[i] = '0' + digit;
        }
        // Instead of modifying each odd position separately,
        // we can directly generate one variant per BFS layer.
        if (st.insert(temp).second) {
            q.push(temp);
        }
    }

    void rotateOperation(const string &s, int b, queue<string> &q) {
        int n = s.size();
        b %= n;
        string new_s = s.substr(n - b) + s.substr(0, n - b);
        if (st.insert(new_s).second) {
            q.push(new_s);
        }
    }

    string findLexSmallestString(string s, int a, int b) {
        string res = s;
        queue<string> q;
        q.push(s);
        st.insert(s);

        while (!q.empty()) {
            string node = q.front();
            q.pop();

            res = min(res, node);

            addOperation(node, a, q);
            rotateOperation(node, b, q);
        }

        return res;
    }
};
