class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Vowels: a, e, i, o, u → indices: 0, 4, 8, 14, 20
        int maxVowel = 0;
        for (int i : {0, 4, 8, 14, 20}) {
            maxVowel = max(maxVowel, freq[i]);
        }

        int maxConsonant = 0;
        for (int i = 0; i < 26; ++i) {
            if (i != 0 && i != 4 && i != 8 && i != 14 && i != 20) {
                maxConsonant = max(maxConsonant, freq[i]);
            }
        }

        return maxVowel + maxConsonant;
    }
};
