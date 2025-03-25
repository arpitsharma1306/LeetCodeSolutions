class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int>& output, vector<vector<int>>& answer, int sum, int idx) {
        if (sum == target) {
            answer.push_back(output);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue; 
            if (sum + candidates[i] > target) break; 

            output.push_back(candidates[i]);
            solve(candidates, target, output, answer, sum + candidates[i], i + 1);
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> output;
        solve(candidates, target, output, answer, 0, 0);
        return answer;
    }
};
