class Solution {
public:
    string normalizeVowels(string s) {
        for (char &c : s) {
            c = tolower(c);
            if (c=='e' || c=='i' || c=='o' || c=='u') c = 'a';
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string> caseInsensitive;
        unordered_map<string,string> vowelInsensitive;

        for (string word : wordlist) {
            string lower = word;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (!caseInsensitive.count(lower))
                caseInsensitive[lower] = word;

            string vword = normalizeVowels(lower);
            if (!vowelInsensitive.count(vword))
                vowelInsensitive[vword] = word;
        }

        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }

            string lower = q;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (caseInsensitive.count(lower)) {
                ans.push_back(caseInsensitive[lower]);
                continue;
            }

            string vq = normalizeVowels(lower);
            if (vowelInsensitive.count(vq)) {
                ans.push_back(vowelInsensitive[vq]);
                continue;
            }

            ans.push_back("");
        }
        return ans;
    }
};
