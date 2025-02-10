class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& word : strs) {
            string sortedWord = word;  
            sort(sortedWord.begin(), sortedWord.end());  // Sort characters to create a unique key
            anagramGroups[sortedWord].push_back(word);  // Group words with the same sorted key
        }

        vector<vector<string>> result;
        for (auto& group : anagramGroups) {
            result.push_back(group.second);
        }

        return result;
    }
};
