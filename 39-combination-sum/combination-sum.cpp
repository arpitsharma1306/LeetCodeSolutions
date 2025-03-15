class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> output;
        sort(candidates.begin(), candidates.end()); // Sort to optimize and avoid unnecessary calls
        solve(candidates, 0, target, output, answer);
        return answer;
    }

    void solve(vector<int>& candidates, int idx, int target, vector<int>& output, vector<vector<int>>& answer) {
        if (target == 0) {
            answer.push_back(output);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break; // Since candidates are sorted, no need to check further
            }
            output.push_back(candidates[i]);
            solve(candidates, i, target - candidates[i], output, answer); // Reuse same element
            output.pop_back(); // Backtrack
        }
    }
};