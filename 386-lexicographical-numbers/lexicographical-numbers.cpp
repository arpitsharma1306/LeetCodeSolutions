class Solution {
public:
    void dfs(vector<int>& ans, int curr, int n) {
        if (curr > n) return;
        ans.push_back(curr);
        for (int i = 0; i < 10; ++i) {
            int next = curr * 10 + i;
            if (next > n) break;
            dfs(ans, next, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= 9; ++i) {
            if (i > n) break;
            dfs(ans, i, n);
        }
        return ans;
    }
};
