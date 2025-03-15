class Solution {
public:
    vector<vector<int>>answer;
    void solve(vector<int>& candidates,int idx,int target,vector<int>output,int sum){
        if(target==sum){
            answer.push_back(output);
            return;
        }
        if(target<sum){
            return;
        }
        
        for(int i=idx;i<candidates.size();i++){
            if (candidates[i] > target-sum) {
                break; 
            }
            output.push_back(candidates[i]);
            solve(candidates,i,target,output,sum+candidates[i]);
            output.pop_back();
        }

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(begin(candidates),end(candidates));
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        vector<int>output;
        solve(candidates,0,target,output,0);
        

        return answer;
    }
};