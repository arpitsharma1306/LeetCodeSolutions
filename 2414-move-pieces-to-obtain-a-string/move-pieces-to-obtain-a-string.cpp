class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // Move i and j to the next non-underscore character
            while (i < n && start[i] == '_')
                i++;
            while (j < n && target[j] == '_')
                j++;

            // If both i and j have reached the end, the strings are
            // transformable
            if (i == n && j == n)
                return true;

            // If one has reached the end but the other hasn't, they are not
            // transformable
            if (i == n || j == n)
                return false;

            // If the characters at i and j are different, they are not
            // transformable
            if (start[i] != target[j])
                return false;

            // If the character is 'L', it can only move to the left
            if (start[i] == 'L' && i < j)
                return false;

            // If the character is 'R', it can only move to the right
            if (start[i] == 'R' && i > j)
                return false;

            // Move to the next character
            i++;
            j++;
        }

        return true;
    }
};