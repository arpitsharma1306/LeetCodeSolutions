class Solution {
public:
    bool isPal(string& s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }

        return true;
    }
    int solve(string&s, int start,int end,vector<vector<int>>& dp){
        if(end<=start){
            return dp[start][end] = 0;
        }

        if(dp[start][end]!=-1){
            return dp[start][end];
        }

        if(isPal(s,start,end)){
            return dp[start][end] = 0;
        }

        int ans = INT_MAX;

        for(int ctr=start;ctr<end;ctr++){
            if(isPal(s,start,ctr)==false){
                continue;
            }

            int tempVal = solve(s,start,ctr,dp) + solve(s,ctr+1,end,dp) + 1;
            ans = min(ans,tempVal);
        }

        return dp[start][end] = ans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> dp (n+1,vector<int>(n+1,-1));
        return solve(s,0,n-1,dp);
    }
};