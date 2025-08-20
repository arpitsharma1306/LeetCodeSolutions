class Solution {
public:
    unordered_set<string> mp;
    unordered_map<int, bool> memo; // for memoization
    
    bool solve(int start, string &s) {
        if (start == s.size()) return true;       // reached end successfully
        if (memo.count(start)) return memo[start]; // already computed
        
        for (int end = start + 1; end <= s.size(); end++) {
            string str = s.substr(start, end - start);
            if (mp.count(str) && solve(end, s)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        mp.clear();
        memo.clear();
        for (string &str : wordDict) {
            mp.insert(str);
        }
        return solve(0, s);
    }
};
