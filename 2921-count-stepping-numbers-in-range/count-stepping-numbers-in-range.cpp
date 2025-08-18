class Solution {
public:
    const int mod = 1e9+7;
    int dp[102][2][2][12];
    long long solve(int idx,bool tight,bool started,int prev,string& num){
        if(idx>=num.size()){
            return started;
        }
        if(dp[idx][tight][started][prev+1]!=-1) return dp[idx][tight][started][prev+1];
        long long res = 0;
        int limit = tight?num[idx]-'0':9;
        for(int d=0;d<=limit;d++){
            bool new_tight = tight && d==limit;
            if(!started){
                res = (res + solve(idx+1,new_tight,started || d!=0,d,num))%mod;
            }else{
                if(abs(d-prev)==1){
                    res = (res + solve(idx+1,new_tight,true,d,num))%mod;
                }
            }
        }

        return dp[idx][tight][started][prev+1] = res;

    }
    bool isStepping(string num){
        if(num.size()==1) return true;
        for(int i=1;i<num.size();i++){
            if(abs(num[i]-num[i-1])!=1) return false;
        }
        return true;
    }
    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof(dp));
        long long cnt1 = solve(0,true,false,-1,low);
        memset(dp,-1,sizeof(dp));
        long long cnt2 = solve(0,true,false,-1,high);

        int ans = (cnt2 - cnt1 + mod) % mod;
        if (isStepping(low)) ans = (ans + 1) % mod;

        return ans;
        
    }
};