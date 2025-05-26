class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (const string& word : words) {
            mp[word]++;
        }

        int cnt = 0;
        bool has_center = false;

        for (auto& [word, freq] : mp) {
            string reversed = string() + word[1] + word[0];

            if (word[0] == word[1]) {
                // Palindromic word like "aa"
                cnt += (freq / 2) * 4;
                if (freq % 2 == 1) has_center = true;
            } else if (mp.find(reversed) != mp.end()) {
                // Pair "ab" with "ba"
                int pair_count = min(freq, mp[reversed]);
                cnt += pair_count * 4;
                // Mark both as used
                mp[reversed] = 0;
            }
            // Mark current word as processed
            mp[word] = 0;
        }

        if (has_center) cnt += 2;

        return cnt;
    }
};
