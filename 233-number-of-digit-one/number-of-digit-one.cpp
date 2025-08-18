class Solution {
public:
    int dp[11][2][11];
    int solve(int idx,bool tight,int ones,string& num){
        if(idx>=num.size()) return ones;

        if(dp[idx][tight][ones] != -1) return dp[idx][tight][ones];
        int res = 0;
        int limit = tight?num[idx]-'0':9;
        for(int d=0;d<=limit;d++){
            bool ntight = tight && d==limit;
            if(d==1) res += solve(idx+1,ntight,ones+1,num);
            else res += solve(idx+1,ntight,ones,num);
        }

        return dp[idx][tight][ones] = res;
    }
    int countDigitOne(int n) {
        string num = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,true,0,num);
    }
};