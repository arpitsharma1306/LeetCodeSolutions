class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Initialize a set to store banned numbers for quick lookup
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        
        int sum = 0;    // To keep track of the current sum of chosen numbers
        int count = 0;  // To count the number of valid numbers chosen

        // Iterate through numbers from 1 to n
        for (int num = 1; num <= n; ++num) {
            // Check if the current number is not banned
            if (bannedSet.find(num) == bannedSet.end()) {
                // Check if adding this number exceeds maxSum
                if (sum + num > maxSum) {
                    break; // Exit the loop if the sum would exceed maxSum
                }
                // Add the current number to the sum and increment the count
                sum += num;
                ++count;
            }
        }

        return count; // Return the total count of valid numbers chosen
    }
};