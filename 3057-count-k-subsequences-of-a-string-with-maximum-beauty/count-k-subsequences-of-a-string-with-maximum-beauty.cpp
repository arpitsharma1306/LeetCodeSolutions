class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<char, int> freq;
    vector<int> power;
    unordered_map<string, int> seen;
    int mx = 0;

    long long solve(int i, int k, int m) {
        if (i == power.size()) {
            return (k == 0 && m == 0) ? 1 : 0;
        }
        if (k < 0 || m < 0) return 0;

        string key = to_string(i) + "#" + to_string(k) + "#" + to_string(m);
        if (seen.count(key)) return seen[key];

        // Include current power
        long long take = (power[i] * solve(i + 1, k - 1, m - power[i])) % mod;

        // Exclude current power
        long long notake = solve(i + 1, k, m);

        return seen[key] = (take + notake) % mod;
    }

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        for (char c : s) {
            freq[c]++;
        }

        if (k > freq.size() || k > 26) return 0;

        for (auto& entry : freq) {
            power.push_back(entry.second);
        }

        sort(power.rbegin(), power.rend());  // Sort descending

        for (int i = 0; i < k; ++i) {
            if (i >= power.size()) return 0;
            mx += power[i];
        }

        return solve(0, k, mx);
    }
};
