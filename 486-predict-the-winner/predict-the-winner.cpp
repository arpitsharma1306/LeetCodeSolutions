class Solution {
public:
    int t[21][21]; // DP table to store results of subproblems

    // Helper function to determine the maximum score a player can achieve
    // by choosing numbers from index `i` to `j`
    int solve(vector<int>& nums, int i, int j) {
        // Base case: If the range is invalid, return 0
        if (i > j) return 0;

        // Base case: If there is only one number left, return it
        if (i == j) return nums[i];

        // If the result for this subproblem is already computed, return it
        if (t[i][j] != -1) {
            return t[i][j];
        }

        // Option 1: Take the number at index `i`
        // The opponent will minimize the score, so take the minimum of the two scenarios:
        // (i+2 to j) or (i+1 to j-1)
        int take_i = nums[i] + min(solve(nums, i + 2, j), solve(nums, i + 1, j - 1));

        // Option 2: Take the number at index `j`
        // Similarly, the opponent minimizes the score:
        // (i to j-2) or (i+1 to j-1)
        int take_j = nums[j] + min(solve(nums, i + 1, j - 1), solve(nums, i, j - 2));

        // Store the maximum score that can be achieved in the current subproblem
        return t[i][j] = max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        // Initialize the DP table with -1
        memset(t, -1, sizeof(t));

        // Calculate the total score of all numbers
        int totalScore = accumulate(nums.begin(), nums.end(), 0);

        // Calculate the maximum score player 1 can achieve
        int player1 = solve(nums, 0, n - 1);

        // Player 2's score is the remaining score
        int player2 = totalScore - player1;

        // Player 1 is the winner if their score is greater than or equal to Player 2's score
        return player1 >= player2;
    }
};
