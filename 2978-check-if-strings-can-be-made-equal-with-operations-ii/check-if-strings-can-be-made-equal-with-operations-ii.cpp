class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> freq1e(26, 0), freq1o(26, 0), freq2e(26, 0), freq2o(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            if (i % 2 == 0) {
                freq1e[s1[i] - 'a']++;
                freq2e[s2[i] - 'a']++;
            } else {
                freq1o[s1[i] - 'a']++;
                freq2o[s2[i] - 'a']++;
            }
        }
        return freq1e == freq2e && freq1o == freq2o;
    }
};
