class Solution {
private:
    // Helper function to perform one pass of removal
    // It removes all occurrences of a given pair (p1, p2) and calculates the score.
    // It returns the score gained and the string after removals.
    pair<int, string> removePairs(const string& s, char p1, char p2, int points) {
        int score = 0;
        string res; // Using a string as a stack
        
        for (char ch : s) {
            if (!res.empty() && res.back() == p1 && ch == p2) {
                score += points;
                res.pop_back();
            } else {
                res.push_back(ch);
            }
        }
        return {score, res};
    }

public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        string remaining_s;
        
        // Always prioritize removing the higher-scoring pair first for maximum gain
        if (x > y) {
            // First pass: remove "ab"
            pair<int, string> result1 = removePairs(s, 'a', 'b', x);
            totalScore += result1.first;
            remaining_s = result1.second;
            
            // Second pass: remove "ba" from the result of the first pass
            pair<int, string> result2 = removePairs(remaining_s, 'b', 'a', y);
            totalScore += result2.first;
        } else { // y >= x
            // First pass: remove "ba"
            pair<int, string> result1 = removePairs(s, 'b', 'a', y);
            totalScore += result1.first;
            remaining_s = result1.second;
            
            // Second pass: remove "ab" from the result of the first pass
            pair<int, string> result2 = removePairs(remaining_s, 'a', 'b', x);
            totalScore += result2.first;
        }
        
        return totalScore;
    }
};