class Solution {
public:
    int dp[1<<14][16];

    int solve(int &n,vector<int>& tasks, int& sessionTime,int remTime,int mask){
        if(mask==0) return 1;

        if(dp[mask][remTime]!=-1) return dp[mask][remTime];

        int min_cnt = INT_MAX;

        for(int i=0;i<n;i++){
            if((mask&(1<<i)) && remTime>=tasks[i]){
                min_cnt = min(min_cnt,solve(n,tasks,sessionTime,remTime-tasks[i],mask^(1<<i)));
            }
        }

        if(min_cnt==INT_MAX) min_cnt = 1 + solve(n,tasks,sessionTime,sessionTime,mask);

        return dp[mask][remTime] = min_cnt;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        memset(dp,-1,sizeof(dp));
        int n=tasks.size();
        int mask = (1<<n)-1;

        return solve(n,tasks,sessionTime,sessionTime,mask);

    }
};