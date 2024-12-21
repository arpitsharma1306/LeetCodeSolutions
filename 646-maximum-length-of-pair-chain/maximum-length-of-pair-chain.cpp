class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),[](const vector<int>&a,const vector<int>& b){
            return a[1]<b[1];
        });

        vector<int>dp;
        dp.push_back(pairs[0][1]);
        for(int i=1;i<n;i++){
            if(dp[dp.size()-1]<pairs[i][0]) dp.push_back(pairs[i][1]);
        }

        return dp.size();
    }
};