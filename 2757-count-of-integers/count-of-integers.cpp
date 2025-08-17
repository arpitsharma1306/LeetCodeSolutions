class Solution {
public:
    int dp[24][402][2];
    const int mod = 1000000007;
    long long solve(int idx,bool tight,int sum,int min_sum, int max_sum,string num){
        if(idx>=num.size()){
            if(sum>=min_sum && sum<=max_sum) return 1;
            else return 0;
        }

        if(dp[idx][sum][tight]!=-1) return dp[idx][sum][tight];

        char limit = tight?num[idx]:'9';
        long long cnt = 0;
        for(char i = '0';i<=limit;i++){
            bool new_tight = tight && (limit==i);
            cnt = (cnt + solve(idx+1,new_tight,sum+(i-'0'),min_sum,max_sum,num))%mod;
        }

        return dp[idx][sum][tight] = cnt;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        long long cnt1 = solve(0,true,0,min_sum,max_sum,num1)%mod;
        memset(dp,-1,sizeof(dp));
        long long cnt2 = solve(0,true,0,min_sum,max_sum,num2)%mod;

        int digit_sum=0;
        for(char i:num1){
            digit_sum+=(i-'0');
        }
        int ans = (cnt2 - cnt1 + mod) % mod;;
        if(digit_sum>=min_sum && digit_sum<=max_sum) ans++;

        return ans;
    }
};