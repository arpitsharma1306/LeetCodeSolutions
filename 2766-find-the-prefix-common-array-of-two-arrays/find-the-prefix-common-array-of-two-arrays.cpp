class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> count(n + 1, 0); // Frequency array for elements 1 to n
        vector<int> result(n, 0);    // Resultant prefix common array
        int prefixCommon = 0;             // Count of common elements in the current prefix

        for (int i = 0; i < n; ++i) {
            // Process element from A
            if (++count[A[i]] == 2) {
                ++prefixCommon;
            }
            // Process element from B
            if (++count[B[i]] == 2) {
                ++prefixCommon;
            }
            // Set the current prefix common count
            result[i] = prefixCommon;
        }

        return result;
    }
};
