class Solution {
public:
    int dp[13][10001];
    int solve(vector<int>& coins, int amount,int idx,int curr_amount){
        if(curr_amount==amount){
            return 0;
        }
        if(curr_amount>amount || idx>=coins.size()){
            return INT_MAX-1;
        }

        if(dp[idx][curr_amount]!=-1){
            return dp[idx][curr_amount];
        }
        int value=coins[idx];
        int res=-1;
        if(value>(amount-curr_amount)){
            int skip = solve(coins,amount,idx+1,curr_amount);
            res = skip;
        }else{
            int taken = 1 + solve(coins,amount,idx,curr_amount+value);
            int skip = solve(coins,amount,idx+1,curr_amount);
            res = min(taken,skip);
        }
        
        return dp[idx][curr_amount] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(coins,amount,0,0);

        return ans==INT_MAX-1?-1:ans;
    }
};