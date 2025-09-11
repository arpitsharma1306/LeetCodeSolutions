class Solution {
public:
    string sortVowels(string s) {
        static const string vowels = "aeiouAEIOU";
        vector<char> collected;
        
        // Collect vowels
        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                collected.push_back(c);
            }
        }

        // Sort vowels
        sort(collected.begin(), collected.end());

        // Replace vowels in original string
        int j = 0;
        for (char &c : s) {
            if (vowels.find(c) != string::npos) {
                c = collected[j++];
            }
        }
        
        return s;
    }
};
